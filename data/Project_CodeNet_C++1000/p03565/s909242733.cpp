#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

int find_index(string s, string t) {
	auto judge = [](string& s, string& t, int idx) {
		if (s.length() - idx < t.length())
			return false;
		bool res = true;
		for (int i = 0; i < t.length(); ++i) 
			res &= (s[idx + i] == t[i] || s[idx + i] == '?');
		return res;
	};
	for (int i = s.length() - 1; i >= 0; --i)
		if (judge(s, t, i))
			return i;
	return -1;
}

int main(void) {
	string S, T; cin >> S >> T;
	int idx = find_index(S, T);
	if (idx == -1) cout << "UNRESTORABLE" << endl;
	else {
		for (int i = 0; i < idx; ++i) {
			if (S[i] == '?') cout << 'a';
			else cout << S[i];
		}
		cout << T;
		for (int i = idx + T.length(); i < S.length(); ++i) {
			if (S[i] == '?') cout << 'a';
			else cout << S[i];
		}
		cout << endl;
	}
	return 0;
} 