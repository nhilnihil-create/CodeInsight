#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i=0;i<n;i++)
#define REP(i, n) for(int i=1;i<=n;i++)
typedef long long ll;

bool comp(const pair<ll, ll> v1, pair<ll, ll> v2) {
	return v1.first - v1.second > v2.first - v2.second;
}

int main() {
	ll n;
	cin >> n;
	vector<pair<ll, ll>> vp(n);
	rep(i, n) cin >> vp[i].first;
	rep(i, n) cin >> vp[i].second;
	sort(vp.begin(), vp.end(), comp);
	ll ans = 0;
	ll count = 0;
	rep(i, n) {
		//
		if (vp[i].first < vp[i].second) {
			ans++;
			count += vp[i].second - vp[i].first;
			vp[i].first = vp[i].second;
		}
	}
	rep(i, n) {
		if (count <= 0) break;
		if (vp[i].first > vp[i].second) {
			count -= vp[i].first - vp[i].second;
			ans++;
		}
	}
	if (count > 0) ans = -1;
	cout << ans << endl;
	return 0;
}