#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define int long long int
#define vi vector<int>
#define vvi vector < vi >
#define pii pair<int,int>
#define mod 1000000007
#define inf 1000000000000000001
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define tr(k,st,en) for(int k = st; k <= en ; ++k)
#define trb(k,en,st) for(int k = en; k >= st ; --k)

using namespace std;

vector<vector<int>> G(100005);
vector<bool> visited(100005, false);
pair<int, int> dfs(int x)
{
    visited[x]=true;
    int w=1,b=1;
    for(auto& i : G[x])
    {
        if(visited[i]==false)
        {
            auto p = dfs(i);
            w = (w * (p.first + p.second)) % mod;
            b = (b * p.first) % mod;
        }
    }
    return make_pair(w, b);
}


int32_t main()
{
    std::ios::sync_with_stdio(false);
    int n,u,v;
    cin>>n;
    for (int i = 1 ; i < n; i++) {
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    auto p = dfs(1);
    cout<<(p.first + p.second)%mod<<endl;
}


