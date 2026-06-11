#include <bits/stdc++.h>
using namespace std;
#define N (int)2e5
#define fi first
#define se second
#define mp make_pair
#define pb push_back
int n,m,memo[N];
vector <int> adj[N];

int dp(int u) {
    if (adj[u].size() == 0) return 0;
    int &sol = memo[u];
    if (sol != -1) return sol;
    int keep = INT_MIN;
    for (int v : adj[u]) {
        keep = max(
            keep ,
            dp(v) + 1
        );
    }
    return sol = keep;
}

int main() {
    scanf("%d%d" , &n , &m);
    for (int i = 1 ; i <= m ; i++) {
        int u,v; scanf("%d%d" , &u , &v);
        adj[u].pb(v);
    }
    memset (memo , -1 , sizeof memo);
    int sol = INT_MIN;
    for (int u = 1 ; u <= n ; u++)
        sol = max(sol , dp(u));
    printf("%d\n" , sol);
}
