#include <bits/stdc++.h>

using namespace std;

const int N = 2048;
int s = 0, n, a[N];
bitset<N*N> dp;

signed main(){
	cin >> n;
	for(int i=0;i<n;++i) cin >> a[i], s += a[i];
	dp[0] = 1;
	for(int i=0;i<n;++i)
		dp = dp | (dp << a[i]);
	for(int i=(s+1)/2;i<=s;++i) if(dp[i]) return cout << i, 0;
	
}