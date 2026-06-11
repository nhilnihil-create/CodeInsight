#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pii pair<int,int>
#define pll pair<lli,lli>
#define vi  vector<int>
#define vii vector<pair<int,int>>
#define vll vector<lli>
#define pb  push_back
#define mp  make_pair
#define ss  second
#define ff  first
#define all(x) sort(x.begin(),x.end())
#define BLACK 0
#define WHITE 1
#define piii pair<int,pii>
const int maxn = 2e5+9;
vector<pii>adj[maxn];
int vis[maxn];
int color[maxn];
void dfs(int curr,int col)
{
    vis[curr]=1;
    color[curr]=col;
    for(pii child:adj[curr])
    {
        if(vis[child.ff]==0)
        {
            int w=child.ss;
            if(w%2==0)dfs(child.ff,col);
            else dfs(child.ff,col^1);
        }
    }
}
void solve()
{
    int n;cin>>n;
    for(int i=1;i<n;i++)
    {
        int a,b,c;cin>>a>>b>>c;
        adj[a].pb(mp(b,c));
        adj[b].pb(mp(a,c));
    }
    dfs(1,BLACK);
    for(int i=1;i<=n;i++)
    {
        cout<<color[i]<<endl;
    }

}

int main()
{
    solve();
}
