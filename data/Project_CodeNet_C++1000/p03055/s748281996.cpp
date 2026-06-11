#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repo(i,n) for(int i = 1; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define np next_permutation
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define pi acos(-1.0)
const ll INF = 1LL<<61;
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
ll jou(ll N, ll P){if(P==0) return 1;
  if(P%2==0){ll t = jou(N, P/2);return t*t % mod;
  }return (N * jou(N, P-1)) % mod;}  //jou(n,mod-2)で逆元
//intの最大値2147483647 ≒ 2×10^9
//long longの最大値9223372036854775807 ≒ 9×10^18
//'大文字'+=32;    で小文字に
//  cout << fixed << setprecision (20);   小数点以下2０桁まで
//実行時間制約2秒では２×10^8回くらいまで計算できる


//—————————————————BFSグラフ————————————————

using Graph = vector<vector<int>>;

int main() {
    // 頂点数と辺数
    int n;
    cin >> n;

    if(n==1){
      cout << "First" << endl;
      return 0;
    }

    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(n);
    rep(i,n-1) {
        int a,b;
        cin >> a >> b;
        G[a-1].pb(b-1);
        G[b-1].pb(a-1);
    }

    // BFS のためのデータ構造
    vector<int> dist(n, -1); // 全頂点を「未訪問」に初期化
    deque<int> que;

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[0] = 0;
    que.pb(0); // 0 を橙色頂点にする

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        int v = que.front(); // キューから先頭頂点を取り出す
        que.pop_front();

        // v から辿れる頂点をすべて調べる
        for (int nv : G[v]) {
            if (dist[nv] != -1) continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[nv] = dist[v] + 1;
            que.pb(nv);
        }
    }

    // 結果出力 (各頂点の頂点 0 からの距離を見る)
    int cho=0;
    int memo;
    rep(i,n){
      if(cho<dist[i]) memo=i;
      cho=max(cho,dist[i]);
    }

    rep(i,n){
      dist[i]=-1;
    }

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[memo] = 0;
    que.pb(memo); // 0 を橙色頂点にする

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        int v = que.front(); // キューから先頭頂点を取り出す
        que.pop_front();

        // v から辿れる頂点をすべて調べる
        for (int nv : G[v]) {
            if (dist[nv] != -1) continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[nv] = dist[v] + 1;
            que.pb(nv);
        }
    }

  cho=0;
  rep(i,n){
    cho=max(cho,dist[i]);
  }

cout << (cho%3==1?"Second":"First") << endl;

}
