#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define debug(x) cerr << #x << " " << x << '\n'
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pli = pair<ll,int>;
const int INF = 0x3f3f3f3f, N = 3e3 + 5;
const ll LINF = 1e18 + 5;
int n;
char s[N];
constexpr int mod = 1e9 + 7;
ll dp[N][N], sum[N];
int main()
{
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	cin >> n >> (s+1);
 	dp[1][1] = 1;
 	sum[1] = 1;
 	for(int i=2; i<=n; i++)
 	{
 		for(int j=1; j<=i; j++)
 		{
 			if(s[i-1]=='>') dp[i][j] = (sum[i-1]-sum[j-1]+mod)%mod;
 			else dp[i][j] = sum[j-1]%mod;
 		}
 		for(int j=1; j<=i; j++) sum[j] = (sum[j-1] + dp[i][j])%mod;
 	}
 	ll ans = sum[n];
 	ans = (ans + mod)%mod;
 	cout << ans;
	return 0;
}
