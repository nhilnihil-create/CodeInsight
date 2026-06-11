#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define rev(r) reverse(r.begin(),r.end())
#define SORT(ar) sort(ar.begin(), ar.end())
#define sz(x) (int)(x).size()
#define len(x) (int)x.length()
#define in(a) scanf("%d",&a)
#define pr(x) printf("%d ",x)
#define endl '\n'
#define read(v,n) for(int h=0;h<n;h++) cin>>v[h];
#define fo(i,a,b) for(i=a;i<b;i++)
#define fi(i,a,b) for(i=a;i>=b;i--)
#define mo 1000000007
#define N 200007
vector<int>adj[100005];
int vis[100005];
ll a[100005][2];

void dfs(int u)
{
    vis[u]=1;
    int i;
    fo(i,0,adj[u].size())
    {
        if(!vis[adj[u][i]]) {
            dfs(adj[u][i]);
            a[u][1]=(a[u][1]*a[adj[u][i]][0])%mo;
            a[u][0]=(a[u][0]*(a[adj[u][i]][0]+a[adj[u][i]][1]))%mo;
        }
    }
}

int main()
{
    int n,i,j,k,x,y;
    cin>>n;
    fo(i,0,n-1)
    {
        in(x); in(y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    fo(i,1,n+1)
    {
        a[i][0]=1;
        a[i][1]=1;
    }
    dfs(1);
    cout<<(a[1][0]+a[1][1])%mo<<endl;
}
