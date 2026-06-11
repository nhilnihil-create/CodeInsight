#include<cstdio>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
ll dp[1 << 18];
ll a[1 << 18];
ll b[1 << 18];
vector<vector<int>> vt;
int main()
{
	ll n;
	scanf("%lld", &n);
	for (int i = 0; i < (1 << n); i++) {
		scanf("%lld", &a[i]);
	}
	vt.resize(n);
	for (int i = 0; i < (1 << n); i++) {
		for (int y = 0; y < n; y++) {
			if (i&(1 << y))continue;
			vt[y].push_back(i);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int y = 0; y < vt[i].size(); y++) {
			int idx = vt[i][y];
			dp[idx | (1 << i)] = max(dp[idx | (1 << i)], a[idx | (1 << i)] + a[idx]);
			dp[idx | (1 << i)] = max(dp[idx | (1 << i)], dp[idx]);
			a[idx | (1 << i)] = max(a[idx | (1 << i)], a[idx]);
		}
	}
	ll dap = 0;
	for (int i = 1; i < (1 << n); i++) {
		dap = max(dap, dp[i]);
		printf("%lld\n", dap);
	}
}
