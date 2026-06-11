#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repo(i,n) for(int i = 1; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define np next_permutation
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define pi acos(-1.0)
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
ll jou(ll N, ll P){if(P==0) return 1;
    if(P%2==0){ll t = jou(N, P/2);return t*t % mod;
    }return (N * jou(N, P-1)) % mod;}  //jou(n,mod-2)で逆元
//intの最大値2147483647 ≒ 2×10^9
//long longの最大値9223372036854775807 ≒ 9×10^18
//'0'+=16;        で大文字に
//'大文字'+=32;    で小文字に
//  cout << fixed << setprecision (20);   小数点以下2０桁まで
//実行時間制約2秒では２×10^8回くらいまで計算できる



//————————BFS迷路の最短経路————————————————

// 四方向への移動ベクトル
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};



int main() {
    int r,c;
    cin >> r >> c;

    // 盤面入力受取 
    vector<string> p(r);
    rep(i,r) {
      cin >> p[i];
    }

    // BFS のためのデータ構造
    vector<vector<int>> dist(r,vector<int>(c,-1)); // 全マスを「未訪問」に初期化
    queue<pair<int,int>> que;

    // 初期条件  黒を全て初期ノードとする)
    rep(i,r){
      rep(j,c){
        if(p[i][j]=='#') {
          dist[i][j] = 0;
          pair<int,int> q=mp(i,j);
          que.push(q);
        }
      }  
    }

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        pair<int,int> v = que.front(); // キューから先頭頂点を取り出す
        que.pop();
      
        //vの上下左右をすべて調べる
        rep(i,4) {
          int nh = v.fi + dx[i];
          int nw = v.se + dy[i];

          // 場外アウトしたり、移動先が壁の場合はスルー
          if (nh < 0 || nh >= r || nw < 0 || nw >= c) continue;
          if (p[nh][nw] == '#') continue;
          
          if (dist[nh][nw] != -1) continue; // すでに発見済みのマスは探索しない

          // 新たなマスについて距離情報を更新してキューに追加する
          dist[nh][nw] = dist[v.fi][v.se] + 1;
          pair<int,int> r=mp(nh,nw);
          que.push(r);
        }
    }

    // 結果出力 (最長距離を見る)
    int ans=0;
    rep(i,r){
      rep(j,c){
        ans=max(ans,dist[i][j]);
      }
    }
  
  cout << ans << endl;
}
