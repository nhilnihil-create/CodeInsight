#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pf push_front
#define pii pair <int, int>
#define all(vv) (vv).begin(), (vv).end()
#define time cerr << '\n' << (double)clock()/CLOCKS_PER_SEC << '\n'; return 0;

int n, m;
map <string, int> mp;
int32_t main() {
	cin >> n;
	for(int i = 0; i < n; ++i) {
		string x; cin >> x;
		++mp[x];
	}
	cin >> m;
	for(int i = 0; i < m; ++i) {
		string x; cin >> x;
		--mp[x];
	}
	int ans = 0ll;
	for(auto it:mp) {
		ans = max(ans, it.second);
	}
	cout << ans;
	time
}