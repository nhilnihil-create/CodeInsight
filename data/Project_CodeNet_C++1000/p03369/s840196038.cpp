#include<iostream>
#include<string>
using namespace std;
int main() {
	string S;
	int cash=700;
	int count = 0;
	cin >> S;
	if (S[0] == 'o') {
		cash+=100;
	}
	if (S[1]== 'o') {
		cash+=100;
	}
	if (S[2] == 'o') {
		cash+=100;
	}
	cout << cash << endl;
}