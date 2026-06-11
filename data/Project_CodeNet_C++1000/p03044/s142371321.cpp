#pragma region Macros
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, n) for(int i=0; i<(n); i++)
#define REPS(i, n) for(int i=0; i<=(n); i++)
#define FOR(i, a, b) for(int i=a; i<(b); i++)
#define FORS(i, a, b) for(int i=a; i<=(b); i++)
// for container x
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define SIZE(v) ((ll)(v).size())
#define MAX(v) *max_element(ALL(v))
#define MIN(v) *min_element(ALL(v))
#define UNIQUE(v) v.erase(unique(ALL(v)), v.end())

struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;

using Edge = pair<int, int>;
using Graph = vector<vector<Edge>>;

#pragma endregion

Graph G;

vector<int> res;

void dfs(int v, int p, int c) {
    res[v] = c;
    for (auto e:G[v]) {
        if (e.first == p) continue;
        if (e.second & 1) dfs(e.first, v, 1-c);
        else dfs(e.first, v, c);
    }
}

int main(){
    int n;
    cin >> n;
    G.assign(n, vector<Edge>());
    res.assign(n, 0);
    REP(i, n-1){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        G[u].push_back(Edge(v, w));
        G[v].push_back(Edge(u, w));
    }
    dfs(0, -1, 1);
    for (auto v:res) cout << v << endl;
    return 0;
}