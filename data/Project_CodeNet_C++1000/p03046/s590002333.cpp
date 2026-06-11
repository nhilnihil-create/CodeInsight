#include<bits/stdc++.h>
#define int long long
#define for0(i, n) for(int i = 0; i < (n); i++)
#define for1(i, n) for(int i = 1; i <= (n);i++)
#define puts(x) cout << x << "\n"
using namespace std;
vector<int>ans;
signed main() {
	int m, k; cin >> m >> k;
	if (m == 1) {
		if (k == 0) puts("0 0 1 1");
		else puts("-1");
		return 0;
	}
	int p = 1; for1(i, m)p *= 2;
	if (p <= k) { puts("-1"); return 0; }
	for0(i, p) if (i != k) ans.push_back(i);
	ans.push_back(k);
	for0(i, p) if (p - i - 1 != k) ans.push_back(p - i - 1);
	ans.push_back(k);
	for0(i, ans.size()) {
		if (i)cout << ' ';
		cout << ans[i];
	}
	cout << "\n";
}