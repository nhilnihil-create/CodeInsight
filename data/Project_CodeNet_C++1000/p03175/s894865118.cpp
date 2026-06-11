#include<bits/stdc++.h>
#define N 2000009
#define ll long long
#define ld long double
#define ff first
#define ss second
#define inf 1000000005
#define mod 1000000007
using namespace std;
vector<int> g[100009];
int n;
pair<ll, ll> dfs(int v, int p = -1) {
    ll white = 1, black = 1;
    for(int i=0;i<g[v].size();i++) {
        int to = g[v][i];
        if(to == p)
            continue;
        pair<ll, ll> child = dfs(to, v);
        white *= (child.first + child.second);
        black *= child.first;
        white %= mod;
        black %= mod;
    }
    return make_pair(white, black);
}
int main() {
    cin>>n;
    for(int i=1;i<n;i++) {
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    pair<ll, ll> ans = dfs(1);
    cout<<(ans.first + ans.second) % mod;
}
