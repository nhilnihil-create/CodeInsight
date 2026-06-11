#include<iostream>
#include<string>
using namespace std;
int main(){
	int A, B, C;
	cin >> A >> B >> C;
	if (A < C){
		if (C < B){
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}
	}
	if (A > C){
		if (C > B){
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}
	}
}