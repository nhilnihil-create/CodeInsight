///Bismillahir Rahmanir Rahim
#include "bits/stdc++.h"

#define                           ll                          long long
#define                           int                         ll
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<ll,ll>
#define                           clr(x)                      memset(x,0,sizeof(x));
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           show(x,y)                   cout<<x<<" : ";for(auto z:y)cout<<z<<" ";cout<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const ll inf=1e18;
const int mod=1e9+7;
const int M=10005;
int d[M],c[M],vis[M];
queue<int>q;
vector<int>adj[M];
int ses[M];
 main()

{
    fast
    int n;
    cin>>n;
    f(i,1,n-1)
    {
        int u,v;
        cin>>u>>v;
        d[u]++;
        d[v]++;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    f(i,1,n)
    {
        if(d[i]==1)q.push(i),vis[i]=1;
    }
    f(i,1,n)cin>>c[i];
    sort(c+1,c+n+1);
    int cur=1,sum=0;
    while(!q.empty())
    {
        int u=q.front();
        ses[u]=c[cur];cur++;
        sum+=ses[u];
        q.pop();
        for(auto v:adj[u])
        {
             if(vis[v]==0)
             {
                 d[v]--;
                 if(d[v]==1)
                 {
                     q.push(v);
                     vis[v]=1;
                 }
             }
        }
    }
    sum-=c[n];
    cout<<sum<<endl;
    f(i,1,n)
    {
        cout<<ses[i]<<" ";
    }
    cout<<endl;
    return 0;

}



































