#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
#define fast_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll dp[1005][1005];
ll a[1005];
bool vis[N],vis1[N];
vector<ll>v[N];
ll mem[10005][10005];
pair<ll,ll>p[N],p1[N];
set<int>s;
map<string,ll>mp;
queue<ll>q;
ll mod=1e9+7,n,m;
main()
{
    fast_IO
    int n,k;
    cin>>n>>k;
    for(int i=0; i<n; i++) cin>>a[i];

    for(int i=a[0]; i<=k; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i-a[j]>=0&&!vis[i-a[j]])
                vis[i]=1;

        }

    }
    if(vis[k]) cout<<"First";
    else cout<<"Second";

}








