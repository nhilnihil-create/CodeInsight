
// C - Dubious Document 2

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	string S, T;
	cin >> S >> T;

	if (S.size() < T.size()) {
		cout << "UNRESTORABLE" << endl;
		return 0;
	}

	bool restorable = false;
	for (int i=S.size() - T.size(); i>=0; i--) {
		bool valid = true;
		for (int j=0; j<T.size(); j++) {
			if (S[i+j] != T[j] && S[i+j] != '?') {
				//cout << "invalid " << i << " " << j << endl; // **** debug ****
				valid = false;
				break;
			}
		}

		if (valid) {
			for (int j=0; j<T.size(); j++) {
				S[i+j] = T[j];
			}

			for (int j=0; j<S.size(); j++) {
				if (S[j] == '?') S[j] = 'a';
			}

			restorable = true;
			break;
		}
	}

	if (restorable) {
		cout << S << endl;
	} else {
		cout << "UNRESTORABLE" << endl;
	}

	return 0;
}