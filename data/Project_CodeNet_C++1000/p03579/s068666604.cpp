#include "bits/stdc++.h"
#define ALL(obj) (obj).begin(),(obj).end()
#define RALL(obj) (obj).rbegin(),(obj).rend()
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = (int)(n); i >= 0; i--)
#define FOR(i,n,m) for(int i = (int)(n); i < int(m); i++)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 6;
const ll LLINF = 4e18;

bool nibu(const vector<vector<int>> &G, vector<int> &p) {
    queue<pair<int, int>> que;
    que.push({0,-1});
    p[0] = 0;
    while (!que.empty()) {
        pair<int, int> v = que.front(); que.pop();
        for (int u : G[v.first]) {
            if (u != v.second) {
                if (p[u] == -1) {
                    p[u] = 1 - p[v.first];
                    que.push({u,v.first});
                }
                else if (p[u] != 1 - p[v.first]) {
                    return false;
                }
            }
        }
    }
  	return true;
}

int main() {
    ll n, m; cin >> n >> m;
    vector<vector<int>> G(n);
    vector<int> p(n, -1);
    REP(i, m) {
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    if (nibu(G, p)) {
        ll cnt = 0;
        REP(i, n) {
            if (p[i] == 0) {
                cnt++;
            }
        }
        cout << (n - cnt)*cnt - m << endl;
    }
    else {
        cout << n*(n - 1) / 2 - m << endl;
    }
    getchar(); getchar();
}