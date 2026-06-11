#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 0x3f3f3f3f, MAX_N =  2e5+10;
int N;
int P[MAX_N];
int dp[MAX_N];

void solve()
{
	int ans = 0;
	for(int i=1;i<=N;++i){
		dp[P[i-1]] = max(dp[P[i-1]], dp[P[i-1]-1]+1);
		ans =  max(ans, dp[P[i-1]]);
	}
	cout << N-ans << '\n';
}

int main()
{
	cin >> N;
	for(int i=0;i<N;++i) cin >> P[i];
	solve();
	return 0;
}