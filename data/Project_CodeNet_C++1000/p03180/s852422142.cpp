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
const int INF = 0x3f3f3f3f, N = 16;
const ll LINF = 1e18 + 5;
int n, a[N][N];
ll dp[1<<N];
int main()
{
 	ios::sync_with_stdio(false);
 	cin.tie(0);
	cin >> n;
	for(int i=0; i<n; i++) 
		for(int j=0; j<n; j++)
			cin >> a[i][j];
	for(int i=1; i<(1<<n); i++)
	{
		for(int j=0; j<n; j++)
			for(int k=j+1; k<n; k++)
				if((i>>j)&1 && (i>>k)&1) dp[i] += a[j][k];
		for(int j=i; j>0; j=(j-1)&i)
		{
			int k = i^j;
			dp[i] = max(dp[i], dp[j]+dp[k]);
		}
	}
	ll ans = dp[(1<<n)-1];
	cout << ans;
	return 0;
}
