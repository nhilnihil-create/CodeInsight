#include<bits/stdc++.h>
using namespace std;
#define int long long
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(i,x) for(auto &i:x)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r)
{
    return l+rng()%(r-l+1);
}
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
#define pii pair<int,int>
#define fi first
#define se second
#define batbit(i,x) (x|(1ll<<i))
#define getbit(i,x) ((x>>i)&1)

const int mn=1e5+10;
int n,m,deg[mn],root,p[mn];
vector<int> ke[mn];

main()
{
    //freopen("test.inp","r",stdin);

    cin >> n >> m;
    forinc(i,1,n-1+m)
    {
        int u,v;
        cin >> u >> v;
        ke[u].push_back(v);
        deg[v]++;
    }
    forinc(i,1,n) if(!deg[i])
    {
        root=i;
        break;
    }
    queue<int> q;
    q.push(root);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        forv(v,ke[u])
        {
            deg[v]--;
        }
        forv(v,ke[u]) if(!deg[v])
        {
            p[v]=u;
            q.push(v);
        }
    }
    forinc(i,1,n) cout << p[i] << "\n";
}
