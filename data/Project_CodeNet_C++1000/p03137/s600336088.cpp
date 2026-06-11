#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1e9+7;
using namespace std;
using ll = long long;

int main() {
	int n, m, ans = 0;
	cin >> n >> m;
	vector<int> x(m);
	rep(i,m) cin >> x[i];
	sort(x.begin(), x.end());
	if (n < m) {
		vector<int> sa(m-1);
		rep(i, m-1) sa[i] = x[i+1] - x[i];
		sort(sa.begin(), sa.end());
		rep(i, m-n) ans += sa[i];
	}
	cout << ans;
	return 0;
}
