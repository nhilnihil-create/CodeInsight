//二色問題
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> l_l;
typedef pair<int , int> i_i;
typedef vector<ll> vel;
typedef vector<int> vei;
typedef vector<char> vec;
typedef vector<bool> veb;
typedef vector<string> ves;
typedef vector<vector<ll>> ve_vel;
typedef vector<vector<int>> ve_vei;
typedef vector<vector<char>> ve_vec;
typedef vector<vector<bool>> ve_veb;
typedef vector<vector<string>> ve_ves;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n);i++)
#define rep2(i,n) for(int i=2;i<(int)(n);i++)
#define repk(i,k,n) for(int i=k;i<(int)(n);i++)
#define fs first
#define sc second
#define pub push_back
#define pob pop_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define maxel(a) *max_element(all(a))
#define minel(a) *min_element(all(a))
#define acc accumulate
#define EPS (1e-7)
//#define INF (1e9)
#define PI (acos(-1))
#define mod (1000000007)
typedef long long int64;
const int64 INF = 1LL << 58;
#define dame { puts("-1"); return 0;}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

using Graph = vector<vector<int>>;

// 二部グラフ判定
vector<int> color;
bool dfs(const Graph &G, int v, int cur = 0) {
    color[v] = cur;
    for (auto next_v : G[v]) {
        if (color[next_v] != -1) {
            if (color[next_v] == cur) return false; // 同じ色が隣接したらダメ
            continue;
        }
        if (!dfs(G, next_v , 1 - cur)) return false;
    }
    return true;
}

//AGC039Bでverify

int main() {
    // 頂点数と辺数
    ll N, M; cin >> N >> M;

    // グラフ入力受取
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b; a--; b--;
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
    ll ans;
    if (is_bipartite) {
        ll B = count(all(color), 0);
        ll W = N - B;
        ans = B * W - M;
    }
    else ans = (N-1) * N / 2 - M;
    cout << ans << endl;
    return 0;
}