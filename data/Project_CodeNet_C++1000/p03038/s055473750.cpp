#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define pb push_back
#define mk make_pair
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	priority_queue<pi>p;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		p.push({x, 1});
	}
	for (int i = 0; i < m; i++) {
		ll how, by;
		cin >> how >> by;
		p.push({by, how});
	}
	ll have = n;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		pi v = p.top();
		ll taken = min(have, p.top().se);
		ans += (taken * p.top().fi);
		have -= taken;
		p.pop();
		if (have == 0)break;
	}
	cout << ans << endl;
}