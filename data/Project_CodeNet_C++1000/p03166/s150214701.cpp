#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <complex>
#include <chrono>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second

using namespace std;
const int MX = 100010;            // maximum no. of nodes in graph
vector<bool> visited(MX+1,0);
vector<int> maxdis(MX+1,0);
int n;
vector< vector<int> > G(MX+1);        // adjacency list, (edge,cost) pair
vector< vector<int> > P(MX+1);

int dfs(int x)
{
    if (visited[x]) {
        return maxdis[x];
    }
    visited[x]=true;
    int ans = 0,t;
    for(auto& i : G[x])
    {
        t = dfs(i);
        if (ans < t) {
            ans = t;
        }
    }
    ans++;
    maxdis[x] = ans;
    return ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
    for(int i=0; i<MX+1; i++)
    {
        G[i].clear();
        P[i].clear();
    }
    fill(all(visited),0);
    int m;                    // no. of edges
    cin>>n>>m;
    for(int i = 1 ; i <= m ; i++)
    {
        int u,v;
        cin>>u>>v;            // 1 based indexing of nodes
        G[u].eb(v);
        P[v].eb(u);
    }
    vector<size_t> sizes(n+1,0);
    int ans = 0,t;
    for (size_t i = 1 ; i <= n; i++) {
        if (P[i].empty()) {
            t = dfs((int)i);
            if (ans < t) {
                ans = t;
            }
        }
    }
    std::cout << ans - 1 << endl;
    
    return 0;
}

