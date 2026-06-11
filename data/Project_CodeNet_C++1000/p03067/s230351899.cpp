#include<iostream>
using namespace std;
int main() {
	int A, B, C;
	cin >> A >> B >> C;
	if ((A < C) && (C < B) || (B < C) && (C < A)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	system("pause");
	return 0;
}