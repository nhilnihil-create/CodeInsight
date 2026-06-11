#include <bits/stdc++.h>
#define int long long
#define S second
#define F first
#define pb push_back
#define sz size()
using namespace std;
const int N=1e6+7;
const int mod=1e9+7;
int b[N],c[N],a[N],dp[N],ans[N] ;
int n,x=1,k,w,m,y ;
vector < int > vec ;
vector < int > adj[N] ;
multiset < int > st ;
void dfs(int x)
{
    for (auto z : adj[x])
    {
        dp[z]=max(dp[z],dp[x]+1) ;
        a[z]-- ;
        if (a[z]==0)
            dfs(z),a[z]=-1 ;
    }
}
main()
{
    cin >> n >> m ;
    for (int i=1; i<=m ; i++)
    {
        cin >> x >> y ;
        adj[x].pb(y) ;
        a[y]++ ;
    }
    for (int i=1; i<=n; i++)
        if (a[i]==0)
            dfs(i) ;
    y=0 ;
    for (int i=1; i<=n; i++)
        y=max(y,dp[i]);
    cout << y << endl ;

}

