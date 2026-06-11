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

// 最大公約数
ll gcd(ll a,ll b){
   if (a%b == 0) return(b);
   else return(gcd(b, a%b));
}

// 最小公倍数
ll lcm(ll a, ll b){
    return a*b/gcd(a, b);
}

int main()
{
    cout << fixed << setprecision(15);
    ll N, M;
    cin >> N >> M;

    vector<ll> A(M);
    vector<ll> B(M);

    REP(i, M){
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        
        A[i] = a;
        B[i] = b;
    }

    ll ans = 0;
    REP(i, M){
         // グラフ入力受取
        Graph G(N);
        for (ll j = 0; j < M; ++j) {
            if(j == i) continue;
            G[A[j]].push_back(B[j]);
            G[B[j]].push_back(A[j]);
        }
        // cout << 2 << endl;
        // 頂点 s をスタートとした探索
        vector<ll> dist(N, -1);
        queue<ll> que;
        ll count = 0;
        for (ll v = 0; v < N; ++v) {
            if (dist[v] != -1) continue; // v が探索済みならスルー
            dist[v] = 0;
            que.push(v);
            while (!que.empty()) {
                int v = que.front(); que.pop();
                for (auto nv : G[v]) {
                    if (dist[nv] == -1) {
                        dist[nv] = dist[v] + 1;
                        que.push(nv);
                    }
                }
                // cout << v << endl;
            }
            ++count;
        }
        if(count > 1) ans++;
    }
   
    cout << ans << endl;
    return 0;
}