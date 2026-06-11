#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

//-----------------------------------
using Edge = pair<int,int>;
using Graph = vector<vector<Edge> >;

int N;
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
    cin >> N;
    G.assign(N, vector<Edge>());
    for (int i=0; i<N-1; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        G[a].push_back(Edge(b,c));
        G[b].push_back(Edge(a,c));
    }

    res.assign(N,0);

    dfs(0,-1,1);

    rep(i,res.size()) {
        cout << res[i] << endl;
    }
}