#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_NC = 200005;
const ll MOD = 1e9+7;
ll c[MAX_NC],colorsum[MAX_NC],dp[MAX_NC];

int main()
{
	int N;
	cin >> N;
	dp[0] = 1;
	rep(i,N)
	{
		cin >> c[i];
		dp[i+1] = dp[i];
		if (i == 0 || c[i] != c[i-1])
		{
			dp[i+1] = (dp[i+1] + colorsum[c[i]]) % MOD;
			colorsum[c[i]] = (colorsum[c[i]] + dp[i]) % MOD;
		}
	}
	cout << dp[N] << endl;
	return 0;
}