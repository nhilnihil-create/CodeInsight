#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 10000000000000000;
const ll mod = 1000000007;
//printf("%.10f\n", n);
signed main() {
	ll n, m, k, s, t, cnt = 0, ans = 0; cin >> n >> m >> k >> s >> t;
	ll l = 0, r = 0, u = 0, d = 0;
	string st, sr; cin >> st >> sr;
	reverse(st.begin(), st.end()); reverse(sr.begin(), sr.end());
	for (int h = 0; h < k; h++) {
		if (st[h] == 'L' && sr[h] == 'R') {
			if (l == 0) { l++; }
			continue;
		}
		if (st[h] == 'L') { l++; } if (sr[h] == 'R') { l = max((ll)0, l - 1); }
		if (st[h] == 'R' && sr[h] == 'L') {
			if (r == 0) { r++; }
			continue;
		}
		if (st[h] == 'R') { r++; } if (sr[h] == 'L') { r = max((ll)0, r - 1); }
		if (st[h] == 'U' && sr[h] == 'D') {
			if (u == 0) { u++; }
			continue;
		}
		if (st[h] == 'U') { u++; } if (sr[h] == 'D') { u = max((ll)0, u - 1); }
		if (st[h] == 'D' && sr[h] == 'U') {
			if (d == 0) { d++; }
			continue;
		}
		if (st[h] == 'D') { d++; } if (sr[h] == 'U') { d = max((ll)0, d - 1); }
		if (l >= m) { cout << "NO" << endl; return 0; }
		if (r >= m) { cout << "NO" << endl; return 0; }
		if (u >= n) { cout << "NO" << endl; return 0; }
		if (d >= n) { cout << "NO" << endl; return 0; }
	}
	if (t - l < 1) { cout << "NO" << endl; return 0; }
	if (t + r > m) { cout << "NO" << endl; return 0; }
	if (s - u < 1) { cout << "NO" << endl; return 0; }
	if (s + d > n) { cout << "NO" << endl; return 0; }
	cout << "YES" << endl;
	return 0;
}