#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string S, T; cin >> S >> T;
	int n = S.size();
	const int p = 26;
	vector<vector<int>> m(p, vector<int>(p, 0));
	for (int i = 0; i < n; i++) {
		m[S[i] - 'a'][T[i] - 'a']++;
	}
	bool ok = true;	
	for (int i = 0; i < p; i++) {
		int cnt = 0;
		for (int j = 0; j < p; j++) {
			if (1 <= m[i][j]) cnt++;
		}
		if (2 <= cnt) ok = false;
	}
	for (int j = 0; j < p; j++) {
		int cnt = 0;
		for (int i = 0; i < p; i++) {
			if (1 <= m[i][j]) cnt++;
		}
		if (2 <= cnt) ok = false;
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}