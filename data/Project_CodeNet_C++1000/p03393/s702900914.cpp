
// A - Diverse Word

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

bool is_in(char needle, string& haystack) {
	return (haystack.find(needle) != string::npos);
}

int main() {
	string S;
	cin >> S;

	if (S == "zyxwvutsrqponmlkjihgfedcba") {
		cout << -1 << endl;
		return 0;
	}

	string ans;
	bool found = false;
	for (char c='a'; c<='z'; c++) {
		if (!is_in(c, S)) {
			cout << S + c << endl;
			return 0;
		}
	}

	string T = S;
	vector<char> C;
	while(1) {
		C.push_back(T.back());
		T.pop_back();
		sort(C.begin(), C.end());
		for (char c : C) {
			T.push_back(c);
			if (T > S) {
				cout << T << endl;
				return 0;
			}
			T.pop_back();
		}
	}

	return 0;
}