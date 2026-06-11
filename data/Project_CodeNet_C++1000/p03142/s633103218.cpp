#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;  
typedef pair<int,int> ii;  
typedef vector<ii> vii;  
typedef list<int> li;  
typedef unordered_map<int,int> mii;

#define ll long long
#define rep(i,n) for (int i = 0; i < (n); i++)  
#define rrep(i,n) for (int i = (n)-1; i >= 0; i--)
#define rap(i,a,n) for (int i = a; i < (n); i++) 
#define rrap(i,n,a) for (int i = (n)-1; i >= a; i--) 

vector<vector<int>> adj,parent;
int n;
vi ans,dp;
vector<bool> visited;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort() {
    visited.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    int m,a,b;
    cin >> n >> m;
    adj.assign(n,vector<int>());
    rep(i,n-1+m) {
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
    }
    topological_sort();
    dp.assign(n,-1);
    for (int v: ans) {
        for (int u: adj[v]) {
            if (dp[u]==-1) {
                dp[u] = v;
            }
        }
    }
    rep(i,n) {
        cout << (dp[i])+1 << '\n';
    }
    return 0;

    //compile: g++ -std=c++14 -O2 -Wall NAME.cpp -o NAME
}