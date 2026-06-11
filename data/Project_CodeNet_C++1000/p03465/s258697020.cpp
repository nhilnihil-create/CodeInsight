#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define fileopen(filename) if (fopen(filename".INP", "r")) {freopen(filename".INP", "r", stdin);freopen(filename".OUT", "w", stdout);}
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i,n) for (int i=1;i<=n;++i)
#define eb emplace_back
#define pb push_back
#define memset(a,i) memset(a,i,sizeof(a))
#define upper(v,a) upper_bound(v.begin(), v.end(), a)
#define lower(v,a) lower_bound(v.begin(), v.end(), a)
#define ii pair<int,int>
#define fi first
#define se second
#define endl '\n'
#define gcd __gcd
const int maxn=1e5+3;
const int INF=1e9+1;
bool dp[2005][maxn];

signed main()
{
    fastio;
    int n;cin>>n;dp[0][0]=1;
    int a[n+1],pre[n+1];pre[0]=0;
    rep(i,n)
    {
    	cin>>a[i];
    	pre[i]=pre[i-1]+a[i];
    }
    rep(i,n)for (int j=0;j<=1e5;++j)
    	if (!dp[i][j])
    	{
    		if (j+a[i]<=1e5)dp[i][j]=dp[i-1][j+a[i]] | dp[i-1][abs(j-a[i])];
    		else dp[i][j]=dp[i-1][abs(j-a[i])];
    	}
    for (int i=0;i<=1e5;++i)if (dp[n][i]){cout<<(pre[n]+i)/2;return 0;}
}
