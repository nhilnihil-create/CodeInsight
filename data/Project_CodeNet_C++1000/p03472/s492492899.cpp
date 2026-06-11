#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	int n, h;
	cin >> n >> h;
	vector<pair<int, int>> a(n);
	int mx = 0;
	rep(i, n) {
		int s, t;
		cin >> s >> t;
		a[i] = {t, s};
		mx = max(mx, s);
	}
	int ans = 0;
	sort(all(a));
	reverse(all(a));
	rep(i, n) {
		if(a[i].first > mx) {
			h -= a[i].first;
			ans++;
			if(h <= 0) {
				cout << ans << endl;
				return 0;
			}
		} else break;
	}
	ans += (h+mx-1) / mx;
	cout << ans << endl;
	return 0;
}