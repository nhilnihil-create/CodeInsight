#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
#define fast_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll a[N],dp[N],f[N];
bool vis[N],vis1[N];
vector<ll>v[N];
pair<ll,ll>p[N],p1[N];
set<int>s;
map<string,ll>mp;
queue<ll>q;
main()
{
    fast_IO

    int n,m,x,y;
    cin>>n>>m;
    for(int i=0; i<m; i++)
        cin>>x>>y,f[y]++,v[x].push_back(y);

    for(int i=1; i<=n; i++)
    {
        if(f[i]==0)
        q.push(i);
    }
    ll mx=0;
    while(!q.empty())
    {
        int p=q.front();

        for(int i=0; i<v[p].size(); i++)
        {
            int ch=v[p][i];
            dp[ch]=max(dp[ch],dp[p]+1);
            mx=max(mx,dp[ch]);

            if(f[ch]-1==0)
                q.push(ch);

            f[ch]--;
        }
        q.pop();
    }


    cout<<mx;

}








