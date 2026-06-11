#include<iostream>		//Library
using namespace std;

int main(){
	int A, B;
	cin >> A >> B;
	int plus = A+B;
	int minus = A-B;
	int kali = A*B;
	
	cout<< max ( max (plus, minus), kali) <<endl;
}