#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	string S, T;
	cin >> S >> T;

	int n = -1;
	for (int i = 0; i < S.size() - T.size() + 1; i++) {
		if ((S.at(i) == T.at(0))||(S.at(i) == '?')) {
			bool b = true;
			string s = S.substr(i, T.size());
			
			for (int j = 0; j < s.size(); j++) {
				if ((s.at(j) != '?')&&(s.at(j) != T.at(j))) {
					b = false;
					break;
				}
			}

			if (b) {
				n = i;
			}
		}
	}

	if (n == -1) {
		cout << "UNRESTORABLE" << endl;
		return 0;
	}

	for (int i = 0; i < T.size(); i++) {
		S.at(n + i) = T.at(i);
	}

	for (int i = 0; i < S.size(); i++) {
		if (S.at(i) == '?') {
			S.at(i) = 'a';
		}
	}
	cout << S << endl;
}
