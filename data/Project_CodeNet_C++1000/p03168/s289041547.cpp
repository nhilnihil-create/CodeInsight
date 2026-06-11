#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=3000;
double p[maxn];
double dp[maxn][maxn];
bool vis[maxn][maxn];
double solve(ll pos, ll h)
{
    if (h<0) return 0.0;
    else if (pos==0) return h==0;
    else if (vis[pos][h]) return dp[pos][h];
    vis[pos][h]=true;
    return dp[pos][h]=p[pos]*solve(pos-1,h-1)+(1.0-p[pos])*solve(pos-1,h);
}
int main()
{
    //freopen("ABC.inp","r",stdin);
    //freopen("ABC.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(vis,false,sizeof(vis));
    ll i,n,h,t;
    double ans=0.0;
    cin>>n;
    for (i=1;i<=n;i++) cin>>p[i];
    for (h=0;h<=n;h++)
    {
        t=n-h;
        if (h>t) ans+=solve(n,h);
    }
    cout<<setprecision(20)<<fixed<<ans<<endl;
}
