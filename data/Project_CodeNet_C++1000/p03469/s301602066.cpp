#include<iostream>
#include<string>

using namespace std;

int main() {
	string S,A;
	cin >> S;
	A = S;
	A[3] = '8';
	cout << A << endl;

	return 0;
}