#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll sum[200010];

int bin_s(int l, int r) {
	ll g = (sum[l] + sum[r]) >> 1;
	int ok = l, ng = r;
	while (ok + 1 < ng) {
		int mid = (ok + ng) >> 1;
		if (sum[mid] <= g)ok = mid; else ng = mid;
	}
	if (g - sum[ok] < sum[ng] - g)return ok; else return ng;
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		ll a; cin >> a;
		sum[i + 1] = sum[i] + a;
	}
	ll ans = 1e15;
	for (int i = 2; i + 2 <= n; i++) {
		int form = bin_s(0, i), lat = bin_s(i, n);
		ll mn = min(sum[form], sum[i] - sum[form]), mx = max(sum[form], sum[i] - sum[form]);
		mn = min(mn, min(sum[lat] - sum[i], sum[n] - sum[lat]));
		mx = max(mx, max(sum[lat] - sum[i], sum[n] - sum[lat]));
		ans = min(ans, mx - mn);
	}
	cout << ans << endl;
	return 0;
}