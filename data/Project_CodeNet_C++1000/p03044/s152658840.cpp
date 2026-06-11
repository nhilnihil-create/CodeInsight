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
const int M=100005;
vector<pi>adj[M];
int dis[M];
bool vis[M];
void bfs(int src)
{
    queue<int>q;
    q.push(src);
    dis[src]=0;
    vis[src]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto x:adj[u])
        {
            int v=x.fi;
            int w=x.si;
            if(vis[v]==0)
            {

                dis[v]=dis[u]+w;
                vis[v]=1;
                q.push(v);
            }
        }
    }

}
 main()

{

    int n;
    scanf("%lld",&n);
    f(i,1,n-1)
    {
        int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        adj[u].pb(mp(v,w));
        adj[v].pb(mp(u,w));
    }
    //done("chk")
    bfs(1);
   // done("chk")
    f(i,1,n)
    {
        //done(dis[i])
        if(dis[i]%2==0)
         {
             printf("0\n");
         }
         else printf("1\n");
    }
    return 0;

}



































