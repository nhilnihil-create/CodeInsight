#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pf push_front
#define pii pair <int, int>
#define mp make_pair
#define all(vv) (vv).begin(), (vv).end()
#define rep(ii, jj, ll, ss) for(int ii = jj; ii < ll; ii += ss)
#define time cerr << '\n' << (double)clock()/CLOCKS_PER_SEC << '\n'; return 0;

string s;
int ans;

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	ans = 0;
	char pre = s[0];
	cerr << pre << '\n';
	rep(i, 1, (int)s.length(), 1) {
		if (s[i] == pre) {
			++ans;
			if (s[i] == '0') s[i] = '1';
			else s[i] = '0';
		}
		pre = s[i];
	}
	cout << ans;
}