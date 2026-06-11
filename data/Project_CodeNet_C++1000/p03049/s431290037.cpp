#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	int n; cin >> n;
	vector<string> s(n);
	ll ans = 0;
	ll BAcnt = 0;
	ll XAcnt = 0;
	ll BXcnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		if (s[i][0] == 'B' && s[i].back() == 'A') {
			BAcnt++;
		}
		else if (s[i].back() == 'A') {
			XAcnt++;
		}
		else if(s[i][0] == 'B') {
			BXcnt++;
		}
		for (int j = 1; j < s[i].size(); j++) {
			if (s[i][j - 1] == 'A' && s[i][j] == 'B') {
				ans++;
			}
		}	
	}
	if (BAcnt == 0) {
		ans += min(XAcnt, BXcnt);
	}
	else { // 0 < BAcnt
		if (XAcnt < BXcnt) {
			ans += XAcnt;
			BXcnt -= XAcnt;
			ans += BAcnt - 1;
			ans += 1;
		}
		else if (BXcnt < XAcnt) {
			ans += BXcnt;
			BXcnt -= BXcnt;
			ans += BAcnt - 1;
			ans += 1;
		}
		else if (XAcnt == 0 && BXcnt == 0) {
			ans += BAcnt - 1;
		}
		else { // XAcnt == BXcnt
			ans += XAcnt;
			ans += BAcnt;
		}
	}
	cout << ans << endl;
	return 0;
}