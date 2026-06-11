#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()

int main() {
#ifdef local
	freopen("in.txt", "r", stdin);
//	freopen("out1.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int m = 1 << n;
	vector<int> a(m);
	vector<pii> c(m);
	for(int i = 0; i < m; i++) {
		cin >> a[i];
		c[i] = make_pair(a[i], 0);
	}
	auto add = [&](pii &a, const pii &b) {
		if(a.se < b.fi) {
			a.se = b.fi;
			if(a.fi < a.se) swap(a.fi, a.se);
			if(a.se < b.se) a.se = b.se;
		}
	};
	for(int i = 1; i < m; i <<= 1)
		for(int j = 0; j < m; j += i * 2)
			for(int k = 0; k < i; k++)
				add(c[i + j + k], c[j + k]);
	vector<int> ans(m);
	for(int i = 1; i < m; i++) {
		ans[i] = c[i].fi + c[i].se;
		ans[i] = max(ans[i], ans[i - 1]);
		cout << ans[i] << '\n';
	}
	return 0;
}
