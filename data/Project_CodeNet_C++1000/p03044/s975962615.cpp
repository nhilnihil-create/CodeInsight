#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define vec(x) vector<x>
#define pb push_back
#define pii pair<ll,ll>
#define vi vector<ll>
#define vii vector<pair<ll,ll>>
#define matrix(x) vector<vector<x>>
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a, b, sizeof a)
#define ff first
#define ss second
#define mp make_pair
const int INF = 1e9;
const int MOD = 1e9 + 7;

vector<vector<pair<long long,long long> > >adj;
ll n;


void bfs()
{   //ll cnt=0;
    queue<ll> q;
    vec(bool) vis(n+1,false);
    vi ans(n+1,0);
    q.push(1);
    vis[1]=true;
    ans[1]=0;
    while(!q.empty())
    {
        ll u=q.front();
        q.pop();
        //ll f=0;
        for(ll i=0;i<adj[u].size();i++)
        {  ll vff=adj[u][i].ff;
          ll vss=adj[u][i].ss;
            if(!vis[vff])
            {
                if(vss%2==0)
                    ans[vff]=ans[u];
                else
                {
                    if(ans[u]==0)
                        ans[vff]=1;
                    else
                        ans[vff]=0;
                }
                vis[vff]=true;
                q.push(vff);
            }
        }
    }
   for(ll i=1;i<n+1;i++)
   {
       printf("%lld\n",ans[i]);
   }
}

void initialize()
{
	ll i,x,y,z;
    scanf("%lld",&n);
    adj=vector<vector<pair<long long,long long> > >(n+1);

    for(i=0;i<n-1;i++)
    {
        scanf("%lld %lld %lld",&x,&y,&z);
        adj[x].pb({y,z});
        adj[y].pb({x,z});
    }
}

int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//ll t;
	//scanf("%lld",&t);

		initialize();
		bfs();

}
