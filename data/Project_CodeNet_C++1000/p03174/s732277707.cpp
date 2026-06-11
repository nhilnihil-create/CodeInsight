#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize ("unroll-loops")

#include <iostream>
#include <vector>

using namespace std;

int upbound;
const int MOD = 1000000007;
vector<int> g, dp;

inline int Solve(const int& x)
{
	if (x == 0) return 1;
	if (dp[x] != -1) return dp[x];
	int p = __builtin_popcount(x), r = 0;
	for (int y = x & g[p - 1]; y; y &= y - 1)
	{
		r += Solve(x & ~(y & -y));
		if (r >= MOD) r -= MOD;
	}
	dp[x] = r;
	return r;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, r;
	char p;
	cin >> n;
	upbound = (1 << n);
	g = vector<int>(n), dp = vector<int>(upbound, -1);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			cin >> p;
			if (p == '1')
				g[i] |= (1 << j);
		}
	cout << Solve(upbound - 1);
}
