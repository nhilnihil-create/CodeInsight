#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
#define fast_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll a[N],b[N],c[N],dp[N][4];
bool vis[N],vis1[N];
vector<ll>v[N];
pair<ll,ll>p[N],p1[N];
set<int>s;
map<string,ll>mp;

main()
{
    fast_IO
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i]>>b[i]>>c[i];
    int ans=0;

    for(int i=1; i<=n; i++)
    {
        dp[i][1]+=(a[i-1]+max(dp[i-1][2],dp[i-1][3]));
        dp[i][2]+=(b[i-1]+max(dp[i-1][1],dp[i-1][3]));
        dp[i][3]+=(c[i-1]+max(dp[i-1][1],dp[i-1][2]));
        ans=max({dp[i][1],dp[i][2],dp[i][3]});
    }
   cout<<ans<<"\n";



}








