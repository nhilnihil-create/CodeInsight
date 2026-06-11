#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define        optimize           ios::sync_with_stdio(0); cin.tie(0);
#define PI    acos(-1.0)
#define pb push_back
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define RESET(a, b) memset(a, b, sizeof(a))
#define pii pair <int, int>
#define pll pair <ll, ll>
#define node second
#define dis first
#define setbiti(x) __builtin_popcount(x)
#define setbitll(x) __builtin_popcountll(x)
#define gcd(a, b) __gcd(a, b)

#define        MX        200005
vector < pii > adj[MX];
bool visited[MX];
int color[MX];

void dfs(int n)
{
    visited[n] = 1;
    for(int i = 0; i < adj[n].size(); i++){
        if(!visited[adj[n][i].node]){
            visited[adj[n][i].node] = 1;
            if(adj[n][i].dis == 1) color[adj[n][i].node] = 1-color[n];
            else color[adj[n][i].node] = color[n];
            dfs(adj[n][i].node);
        }
    }
}
int main()
{
    optimize
    int n;
    cin>>n;

    for(int i = 0; i < n-1; i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back(pii(w&1, v));
        adj[v].push_back(pii(w&1, u));
    }

    dfs(1);

    for(int i = 1; i <= n; i++) cout<<color[i]<<endl;
}
