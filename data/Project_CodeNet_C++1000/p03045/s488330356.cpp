#include <bits/stdc++.h>
using namespace std;

// 型定義
typedef long long ll;
typedef pair<ll, ll> P;

// forループ
#define REP(i,n) for(ll i=0; i<(ll)(n); ++i)

// 定数宣言
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

// グラフ表現
using Graph = vector<vector<int>>;

// グラフの辺表現
using Edge = map<pair<int,int>,int>;

// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

// 深さ優先探索
vector<bool> seen;
vector<ll> color;

void dfs(const Graph &G, ll v, ll c) {
    seen[v] = true;
    color[v] = c;
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue;
        dfs(G, next_v, c); // 再帰的に探索
    }
}

int main()
{
    cout << fixed << setprecision(15);
    ll N, M;
    cin >> N >> M;

    // グラフ入力受取
    Graph G(N);

    REP(i, M){
        ll x, y, z;
        cin >> x >> y >> z;

        G[x-1].push_back(y-1);
        G[y-1].push_back(x-1);
    }

    seen.assign(N, false);
    color.assign(N, -1);

    REP(i, N){
        if(seen[i] == false) dfs(G, i, i);
    }

    map<ll,ll> MAP;

    REP(i, N){
        MAP[color[i]];
        // cout << color[i] << endl;
    }

    cout << MAP.size() << endl;

    return 0;
}