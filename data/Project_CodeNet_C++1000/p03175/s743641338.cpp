#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F first
#define S second
#define ii pair < int , int >
#define ever (;;)

const int N = 100100;

bool vis[N][2];
ll n,mem[N][2],mod=1e9+7;
vector <int> adj[N];

ll dp(int i,int color,int v)
{
    ll &ret = mem[i][color];
    if( vis[i][color] )
        return ret;
    vis[i][color] = 1;

    ret = 1;

    for(auto &x:adj[i])
    {
        if( x == v )
            continue;

        if( color )
            ret = ret*dp(x,0,i)%mod;
        else
            ret = ret*(dp(x,0,i)+dp(x,1,i))%mod;
    }

    return ret;
}

int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    printf("%lld\n",(dp(1,0,1)+dp(1,1,1))%mod);
}
