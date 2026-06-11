#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() { 
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<vector<bool>> a(n, vector<bool> (26));
	vector<vector<bool>> b(n, vector<bool> (26));
	a[0][s[0] - 'a'] = 1;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < 26; ++j) {
			a[i][j] = a[i - 1][j];
		}
		a[i][s[i] - 'a'] = 1;
	}
	b[n - 1][s[n - 1] - 'a'] = 1;
	for (int i = n - 2; i >= 0; --i) {
		for (int j = 0; j < 26; ++j) {
			b[i][j] = b[i + 1][j];
		}
		b[i][s[i] - 'a'] = 1;
	}
	int ans = 0;
	for (int i = 0; i + 1 < n; ++i) {
		int p = 0;
		for (int j = 0; j <  26; ++j) {
			p += min(a[i][j],b[i + 1][j]);
		}
		ans = max(ans,p);
	}
	cout << ans;
}
