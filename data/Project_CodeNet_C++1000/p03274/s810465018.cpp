#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> x(n);
	rep(i, n) cin >> x[i];
	ll ans = 1LL << 60;
	vector<ll> neg, pos;
	rep(i, n) {
		if(x[i] > 0) pos.push_back(x[i]);
		else if(x[i] == 0) k--;
		else neg.push_back(-x[i]);
	}
	reverse(all(neg));
	if(k == 0) {
		cout << 0 << endl;
		return 0;
	}
	rep(i, pos.size()) {
		if(i > k - 1) continue;
		if(i == k-1) {
			ans = min(ans, pos[i]);
			continue;
		}
		if(k-i-2 >= neg.size()) continue;
		ll now = pos[i] * 2 + neg[k-i-2];
		ans = min(ans, now);
		// cout << pos[i] << " " << neg[k-i-2] << endl;;
	}
	rep(i, neg.size()) {
		if(i > k - 1) continue;
		if(i == k-1) {
			ans = min(ans, neg[i]);
			continue;
		}
		if(k-i-2 >= pos.size()) continue;
		ll now = neg[i] * 2 + pos[k-i-2];
		ans = min(ans, now);
	}
	cout << ans << endl;
	return 0;
}