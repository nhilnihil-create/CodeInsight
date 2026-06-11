#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL)


int main() {
	fastIO;
	int n, m;
	cin >> n >> m;
	vector<ll> v(n);
	for (auto& i : v) {
		cin >> i;
	}
	vector<pair<ll, ll>> vv;
	for (int i = 0; i < m; i++) {
		ll b, c;
		cin >> b >> c;
		vv.push_back({c, b});
	}
	sort(v.begin(), v.end());
	sort(vv.rbegin(), vv.rend());
	int curr = 0, vvptr = 0;
	ll total = 0;
	while(curr < n && vvptr < m) {
		int st = curr, en = n-1, mid, ans=-1;
		while(st <= en) {
			mid = (st+en)/2;
			if (v[mid] <= vv[vvptr].first) {
				st = mid+1;
				ans = mid;
			}
			else {
				en = mid-1;
			}
		}
		if (ans == -1) {
			vvptr++;
			continue;
		}
		int dist = min(vv[vvptr].second, (ll)ans-curr+1);
		total += dist*vv[vvptr].first;
		curr = min(curr+vv[vvptr].second, (ll)ans+1);
		vvptr++;
	}
	for (int i = curr; i < n; i++) {
		total += v[i];
	}
	cout << total;


}
