#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
#define fast_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll a[N],dp[N];
bool vis[N],vis1[N];
vector<ll>v[N];
pair<ll,ll>p[N],p1[N];
set<int>s;
map<string,ll>mp;

main()
{
    fast_IO
    int n,k;
    cin>>n>>k;
    for(int i=0; i<n; i++)
        cin>>a[i];
    for(int i=1; i<n; i++)
        dp[i]=1e18;

    for(int i=1; i<n; i++)
    {
        for(int j=1; j<=k; j++)
        {
            if(i>=j)
                 dp[i]=min(dp[i-j]+abs(a[i]-a[i-j]),dp[i]);
        }
    }
    cout<<dp[n-1];

}








