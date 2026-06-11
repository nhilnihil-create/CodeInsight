#include<iostream>

using namespace std;

int main() {
	string A, B;
	cin >> A >> B;

	if (A[0] == B[2] && A[1] == B[1] && A[2] == B[0]) cout << "YES" << endl;
	else cout << "NO" << endl;
}