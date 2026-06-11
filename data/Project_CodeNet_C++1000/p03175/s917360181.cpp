#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007
#define pb push_back

class grafo {
	int n;
	vector<vector<pair<int, int>>> adj;

public:

    vector<ll> dp_preto, dp_branco;

	grafo(int n) {
		this->n = n;
		adj = vector<vector<pair<int, int>>>(n);
        dp_preto = vector<ll>(n, 1);
        dp_branco = vector<ll>(n, 1);
	}

	void aresta(int u, int v, int w) {
		adj[u].pb({v, w});
		adj[v].pb({u, w});
	}

    void dfs(int u, int pai = -1) {
        for (auto &v : adj[u]) {
            if (v.first == pai) continue;
            dfs(v.first, u);
            dp_branco[u] *= (dp_preto[v.first] + dp_branco[v.first]);
            dp_preto[u] *= dp_branco[v.first];
            dp_branco[u] %= MOD;
            dp_preto[u] %= MOD;
        }
	}

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x, y;
    cin >> n;
    grafo g(n);
    for (int i = 0; i < n-1; i++) {
        cin >> x >> y;
        g.aresta(x-1, y-1, 1);
    }
    g.dfs(0);
    cout << (g.dp_preto[0] + g.dp_branco[0]) % MOD;
}