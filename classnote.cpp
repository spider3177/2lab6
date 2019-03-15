//binary tree
#include <iostream>
using namespace std;

class node{
	public:
	//data to store 
	int data;
	// making the node pointers
	node * left;
	node * right;
	//making the constructor
	node(int val){
		data = val;
		right = NULL;
		left = NULL;
	}
};

class bst{
	public:
	node * root;
	bst(){
		root=NULL;
	};
	void ins(int value){
		insh(root, value);
	}
	void insh(node * curr, int value){
		//base case if curr is null insert there
		if(curr == NULL){
			curr = new node(value);
			if (root == NULL) root = curr;
			return;
		}
		
		//else compare curr data with value
		else if (value < curr->data){
			if (curr->left==NULL)curr->left = new node(value);
			//if value < curr data -> move left and inserthelper
			else insh(curr->left,value);
		}

			//else move right and call inserthelper
		else if (value > curr->data){
			if (curr->right==NULL) curr->right = new node(value);
			else insh(curr->right,value);
		}
	}
	void display(){
		display2(root);
	}
	void display2(node * curr){
	//base condition
		if(curr == NULL) return;
	//display left
		display2(curr->left);
	//display current 
		cout<<curr->data<<",";
	//display right
		display2 (curr->right);


	}
	node * search(node * curr, int val){
	//if reached the end of the tree , or found the value
		if (curr == NULL || curr->data == val) return;
	//if could not find the value
		else if (val<curr->data) return search(curr->left,val);
		else return search(curr->right,val);
	}
	//next class friday
	//height();
	//deletenode();
	











};




int main(){
	bst b1;
	b1.ins(4);
	b1.ins(3);
	b1.ins(7);
	b1.ins(2);
	b1.ins(5);
	b1.display();
	cout<<endl;

return 0;
}

