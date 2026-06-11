//default
#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
typedef pair<int, int> P_i;
typedef pair<double,double> P_d;
#define rep(i,n) for(int i=0;i<(n);++i)
#define alrep(i,j,n) for(int i=0;i<(n);++i)for(int j=i+1;j<(n);++j)
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;int ans=0;
#define answer cout << ans << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const int MOD=1e9+7;
const long long INF = 1LL << 60;

using Graph = vector<vector<int>>;
vector<int> color;
int b=0,w=0;
bool dfs(const Graph &G, int v, int cur = 0) {
    color[v] = cur;
    if(cur==0) b++;
    else if(cur==1) w++;
    for (auto next_v : G[v]) {
        // 隣接頂点がすでに色確定していた場合
        if (color[next_v] != -1) {
            if (color[next_v] == cur) return false; // 同じ色が隣接したらダメ
            continue;
        }

        // 隣接頂点の色を変えて、再帰的に探索 (一回でも false が返ってきたら false)
        if (!dfs(G, next_v , 1 - cur)) return false;
    }
    return true;
}

signed main() {
    // 頂点数と辺数
    int N, M; cin >> N >> M;
    // グラフ入力受取
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 探索
    color.assign(N, -1);
    bool is_bipartite = true;
    for (int v = 0; v < N; ++v) {
        if (color[v] != -1) continue; // v が探索済みだったらスルー
        if (!dfs(G, v)) is_bipartite = false;
    }

    if (is_bipartite){
      cout << b*w-M << endl;
    }
    else{
      cout << N*(N-1)/2-M << endl;
    }
}
