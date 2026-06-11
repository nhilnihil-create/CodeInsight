#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
#define fast_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll dp[1005][1005];
string b[1005];
char a[1005][1005];
bool vis[N],vis1[N];
vector<ll>v[N];
ll mem[10005][10005];
pair<ll,ll>p[N],p1[N];
set<int>s;
map<string,ll>mp;
queue<ll>q;
ll mod=1e9+7,n,m;
/*ll dp(ll i,ll j)
{
    if(a[i][j]=='#')
        return 0;
    if(i==n&&j==m)
        return 1;
        ll p1=0,p2=0;
        ll &ret=mem[i][j];
        if(ret!=-1)
            return ret%mod;
    if(i+1<=n)
        p1=dp(i+1,j)%mod;
    if(j+1<=m)
    p2=dp(i,j+1)%mod;
    return (p1+p2)%mod;

}*/
main()
{
    fast_IO
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>b[i];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            a[i][j]=b[i][j-1];
    }

    dp[1][1]=1;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i][j]=='#')
                continue;
            if(i==1&&j==1)
                continue;

            else
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;

        }
    }
    cout<<dp[n][m];


}








