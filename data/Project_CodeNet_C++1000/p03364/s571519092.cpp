#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld  = long double;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
const int INF=1e9+7;
const ll LINF=9223372036854775807;
const ll MOD=1e9+7;
const ld PI=acos(-1);
const ld EPS = 1e-10; //微調整用（EPSより小さいと0と判定など）

int ii() { int x; if (scanf("%d", &x)==1) return x; else return 0; }
long long il() { long long x; if (scanf("%lld", &x)==1) return x; else return 0; }
string is() { string x; cin >> x; return x; }
char ic() { char x; cin >> x; return x; }
void oi(int x) { printf("%d ", x); }
void ol(long long x) { printf("%lld ", x); }
void od_nosp(double x) { printf("%.15f", x); } // 古い問題用
void od(double x) { printf("%.15f ", x); }
// long doubleで受け取り、fをLfなどに変えて出力すると、変な数値が出る
// それをなんとかするには独自の出力を作らなければならなそう
void os(const string &s) { printf("%s ", s.c_str()); }
void oc(const char &c) { printf("%c ", c); }
#define o_map(v){cerr << #v << endl; for(const auto& xxx: v){cout << xxx.first << " " << xxx.second << "\n";}} //動作未確認
void br() { putchar('\n'); }

// #define gcd __gcd //llは受け取らない C++17~のgcdと違うので注意
// int lcm(int a, int b){return a / gcd(a, b) * b;}
#define b_e(a) a.begin(),a.end() //sort(b_e(vec));
#define REP(i,m,n) for(ll i=(ll)(m) ; i < (ll)(n) ; i++ )
#define DREP(i,m,n) for(ll i=(ll)(m) ; i > (ll)(n) ; i-- )
#define rep(i,n) REP(i,0,n)
#define m_p(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define p_b push_back
#define SZ(x) ((ll)(x).size()) //size()がunsignedなのでエラー避けに
#define endk '\n'


// coutによるpairの出力（空白区切り）
template<typename T1, typename T2> ostream& operator<<(ostream& s, const pair<T1, T2>& p) {return s << "(" << p.first << " " << p.second << ")";}
// coutによるvectorの出力（空白区切り）
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i]; if (i < len - 1) s << " "; //"\t"に変えるとTabで見やすく区切る
  }
  return s;
}
// coutによる多次元vectorの出力（空白区切り）
template<typename T> ostream& operator<<(ostream& s, const vector< vector<T> >& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) {
    s << vv[i] << endl;
  }
  return s;
}

//最大値、最小値の更新。更新したor等しければtrueを返す
template<typename T>
bool chmax(T& a, T b){return (a = max(a, b)) == b;}
template<typename T>
bool chmin(T& a, T b){return (a = min(a, b)) == b;}

//4近傍（上下左右） rep(i, 2) にすると右・下だけに進む
vector<int> dx_4 = {1, 0, -1, 0};
vector<int> dy_4 = {0, 1, 0, -1};

// -------- template end - //


// - library ------------- //



// --------- library end - //



int main(){

  ll N = il();
  vector<string> cells(N);
  rep(i, N) cells[i] = is();
  
  // この問題は、ドラクエのマップのように両端が繋がったマップ上で、斜め45°に線対称な枠の取り方がいくつあるか、という問題と考えられる
  
  // そこから一歩進み、ドラクエのマップのように両端が繋がった盤面とはどんな図形かというと、ドーナツ状の立体に配置された盤面と考えられる
  // 参考1 : https://www.nicovideo.jp/watch/sm22634285
  // 参考2 : https://nlab.itmedia.co.jp/nl/articles/1108/05/news036.html

  // このように無限に繋がった盤面と考えたとき、問題文で与えられた「よい盤面」はどのように言い換えられるか？

  // --> 右斜め45°の線を中心として、左右対称に文字が配置されていて、それがずっと繋がって、最終的にぐるーっと円（円筒）になっている（イメージとしては、トイレットペーパーの芯）ように捉えられる
  // （もしくは、無限の平面で考えれば、ずっと斜めに左右対称な模様が続く。線対称なパターンを一様に敷き詰めた壁紙をイメージするといい。）

  // ここで、円筒（もしくは平面の線対称な部分）を線対称な部分を中心にしながらぐるーっと回していくと、どの部分で横に（対称となる軸と垂直に）切り取って平面にしても、やはり線対称になっていることが分かる
  // この「線対称」というのは「よい盤面」ということであり、このことを元の設定に戻して考えてみると、「一つよい盤面が見つかったら、斜めにどれだけずらしてもよい盤面であり続ける」ということが分かる。


  // ということで、H = 0, W = 0 ~ N-1 について、よい盤面であるかを愚直に確認し、よい盤面の数 × N すると答えとなる。（斜めにいくつずらせるかというと、それぞれ N 種類のずらし方があるから。図形でイメージしてもいいし、単純に「N回でループする世界だから」と考えてもいい）


  // ループする盤面を処理しやすくするため、盤面を2倍化（横に同じ盤面を並べる）
  rep(i, N){
    cells[i] = cells[i] + cells[i];
  }

  ll ans = 0;
  ll h = 0; // 起点となる（一番左上の）セルのy座標 0固定
  rep(w, N){
    // w := 起点となる（一番左上の）セルのx座標 : 0 ~ N-1
    bool ok = true;
    REP(dh, 1, N) rep(dw, N-1){
      // dh := 起点からいくつ下にいったセルを見るか : 1 ~ N-1
      // dw := 起点からいくつ右にいったセルを見るか : 0 ~ N-2
      if (cells[h+dh][w+dw] != cells[h+dw][w+dh]){
        // どことの一致判定をすればいいかというと、右上セル(h, w)を原点としてベクトル(dh, dw)を反転すればいいわけだから、dh と dw を反転すればいい
        ok = false;
        break;
      }
    }
    if (ok) ans++;
  }

  ans *= N;

  cout << ans << endk;



}

