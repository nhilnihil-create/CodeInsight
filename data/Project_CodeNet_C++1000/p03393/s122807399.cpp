#include <bits/stdc++.h>
using namespace std;

int main() {
	string S;
	cin >> S;

	bool sein[26] = { false };
	if (S.length() < 26) {
		for (char c : S) sein[c - 'a'] = true;
		cout << S;
		for (int i = 0; i < 26; i++) {
			if (!sein[i]) {
				cout << (char)('a' + i) << endl;
				break;
			}
		}
	}
	else {
		if (S == "zyxwvutsrqponmlkjihgfedcba") {
			cout << -1 << endl;
			return 0;
		}
		string origin = S;
		next_permutation(S.begin(), S.end());
		for (int i = 0; i < S.length(); i++) {
			cout << S.at(i);
			if (origin.at(i) != S.at(i)) break;
		}
		cout << endl;
	}
}
