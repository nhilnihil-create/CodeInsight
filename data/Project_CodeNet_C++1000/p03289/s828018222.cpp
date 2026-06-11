#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string S;
	cin >> S;

	string A = S.substr(2, S.size() - 3);

	if (S[0] == 'A') {
		if (count(A.begin(), A.end(), 'C') == 1) {
			sort(S.begin(), S.end());
			int Q = 0;
			for (int i = 0; i < S.size(); i++) {
				if (islower(S[i])) Q++;
			}

			if (S.size() - Q == 2) {
				cout << "AC" << endl;
				return 0;
			}
			else {
				cout << "WA" << endl;
				return 0;
			}
		}
		else {
			cout << "WA" << endl;
			return 0;
		}
	}
	else cout << "WA" << endl;

}
