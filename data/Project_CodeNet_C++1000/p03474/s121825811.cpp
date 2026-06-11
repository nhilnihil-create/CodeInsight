#include <iostream>

using namespace std;

int main()
{
	int A, B;
	cin >> A >> B;
	string S;
	cin >> S;

	for (int i = 0; i < S.length(); i++) {
		if (i < A) {
			if (!('0' <= S[i] && S[i] <= '9')) {
				cout << "No" << endl;
				return 0;
			}
		}
		else if(i == A) {
			if (S[i] != '-') {
				cout << "No" << endl;
				return 0;
			}
		}
		else {
			if (!('0' <= S[i] && S[i] <= '9')) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
}



