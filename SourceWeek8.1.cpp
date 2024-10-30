#include <iostream>
using namespace std;
struct node {
	int a; // a la he so
	int n; // n la so mu
	node* next;
};
// Ham tao node moi
node *taonode(int a1, int n1) {
	node* newNode = new node;
	newNode->a = a1;
	newNode->n = n1;
	newNode->next = NULL;
	return newNode;	
}
// Ham them node vao cuoi danh sach
void themnode(node*& head, int a1, int n1) {
	if (a1 == 0) return; // he so = 0 khong them vao danh sach
	node* newNode = taonode(a1, n1);
	if (head == NULL) {
		head = newNode;
	}
	else {
		node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
}
// Ham nhap da thuc
void nhapdathuc(node*& head) {
	int a1;
	int n1;
	int i = 0;
	cout << "Bat dau nhap da thuc(nhap he so 0 de ket thuc): " << endl;
	do {
		i++;
		cout << "Nhap so phan tu thu" << i << endl;
		cout << "Nhap he so =";
		cin >> a1;
		if (a1 == 0) break;
		cout << "Nhap so mu=";
		cin >> n1;
		themnode(head, a1, n1);
	} while (a1 != 0);
	cout << "Ket thuc nhap" << endl;
}
// Ham in da thuc
void indathuc(node* head) {
	if (head == NULL) {
		cout << "0" << endl;
		return;
	}
	node* temp = head;
	while (temp != NULL) {
		cout << temp->a << "x^" << temp->n;
		temp = temp->next;
		if (temp != NULL && temp->a > 0) {
			cout << " + ";
		}
		cout << endl;
	}
}
// Ham xoa danh sach de giai phong bo nho
void giaiphong(node * &head) {
			node* xoa = head;
			node* next = NULL;
			while (xoa != 0) {
				next = xoa->next;
				delete xoa;
				xoa = next;
			}
			head = NULL;
		}
int main() {
	node* x = NULL;
	nhapdathuc(x);
	indathuc(x);
	giaiphong(x);
	return 0;
}




