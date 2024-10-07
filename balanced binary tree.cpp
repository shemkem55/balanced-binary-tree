#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper function to check the height of the tree
int checkHeight(TreeNode* node) {
    // Base case: an empty tree is balanced and has height -1
    if (node == nullptr) {
        return 0; // Height of an empty subtree is 0
    }

    // Check the height of the left subtree
    int leftHeight = checkHeight(node->left);
    if (leftHeight == -1) return -1; // Left subtree is unbalanced

    // Check the height of the right subtree
    int rightHeight = checkHeight(node->right);
    if (rightHeight == -1) return -1; // Right subtree is unbalanced

    // Check if current node is balanced
    if (abs(leftHeight - rightHeight) > 1) {
        return -1; // Current node is unbalanced
    }

    // Return the height of the current node
    return max(leftHeight, rightHeight) + 1;
}

// Function to determine if a binary tree is height-balanced
bool isBalanced(TreeNode* root) {
    return checkHeight(root) != -1;
}

// Example usage
int main() {
    // Create a sample binary tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    if (isBalanced(root)) {
        cout << "The binary tree is height-balanced." << endl;
    } else {
        cout << "The binary tree is not height-balanced." << endl;
    }

    // Clean up memory (not shown for brevity)
    
    return 0;
}