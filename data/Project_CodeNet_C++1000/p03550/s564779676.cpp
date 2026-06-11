#include <bits/stdc++.h>

using namespace std;
const int N = 2005;
int n, x, y, a[N], dp[N][N][2];
int sol(int i, int last, int bit)
{
	if(i == n-1) return abs(a[n-1]-a[last]);
	int &ret = dp[i][last][bit];
	if(ret != -1) return ret;
	if(bit)
	{
		ret = min(sol(i+1, last, bit), sol(i+1, i, bit^1));
	}
	else ret = max(sol(i+1, last, bit), sol(i+1, i, bit^1));
	return ret;
}
int main()
{
	cin >> n >> x >> y;
	for(int i=0; i<n; i++) cin >> a[i];
	memset(dp, -1, sizeof dp);
	a[n] = y;
	cout << sol(0, n, 0) << endl;
}