#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F first
#define S second
#define ii pair < int , int >
#define ever (;;)

const int N = 100100;

int n,m,out[N],dp[N],ans;
vector <int> adj[N];
queue <int> q;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        adj[b].push_back(a);
        out[a]++;
    }

    for(int i=1;i<=n;i++)
        if( !out[i] )
            q.push(i);

    while( !q.empty() )
    {
        int u = q.front();

        q.pop();

        for(auto &x:adj[u])
        {
            dp[x] = max( dp[x] , dp[u] + 1 );
            ans = max( ans , dp[x] );
            out[x]--;
            if( !out[x] )
                q.push(x);
        }
    }

    printf("%d\n",ans);
}
