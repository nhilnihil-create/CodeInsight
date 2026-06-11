#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#ifndef LOCAL
#define endl '\n'
#endif

const int mod = 1e9 + 7;

int pwr(int a,int b) {
	int ans = 1;
	while(b) {
		if(b & 1) ans = (ans * 1LL * a) % mod;
		a = (a * 1LL * a) % mod;
		b >>= 1;
	}
	return ans;
}

void yes() {
	cout << "Yes" << endl;
	exit(0);
}

void no() {
	cout << "No" << endl;
	exit(0);
}

const int N = 1e5 + 5;
int a[N];

void solve() {
	string s;
	cin >> s;
	int ca = 0;
	int n = s.size();
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'A') {
			ca++;
		}
		else if(i + 1 < n && s[i] == 'B' && s[i + 1] == 'C') {
			ans += ca;
			i++;
		}
		else {
			ca = 0;
		}
	}
	cout << ans;
}

signed main() {
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	// cin >> t;
	t = 1;
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}