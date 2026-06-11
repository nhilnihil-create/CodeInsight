#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define A(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
void _read();

const int nax = 1e5 + 11, mod = 1e9 + 7;
int n;
vector<int> adj[nax];
int dp[nax][2];

void dfs( int u = 1, int p = 1 ) {
      bool is = true;
      dp[u][0] = dp[u][1] = 1;
      for( int v : adj[u]) {
            if ( v == p ) continue; 
            dfs(v,u);
            (dp[u][0] *= (dp[v][0]+dp[v][1])%mod) %= mod;
            (dp[u][1] *= dp[v][0]) %= mod;
      }
}

main () { _read(); 
      cin >> n;
      for( int i = 1; i < n; i++) {
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b); 
            adj[b].push_back(a);
      }
      dfs();
      cout << (dp[1][0] + dp[1][1]) % mod << '\n';
      return 0;
};

void _read() {
      ios_base :: sync_with_stdio(false);
      cin.tie(NULL);
      #ifdef LOCAL
      freopen("input.txt","r",stdin);
      #endif
}
