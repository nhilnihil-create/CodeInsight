/*    特徴    */

/*    教訓    */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld  = long double;
using pint = pair<int, int>;
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
int lcm(int a, int b){return a / gcd(a, b) * b;}
#define begin_end(a) a.begin(),a.end() //sort(begin_end(vec));
#define REP(i,m,n) for(ll i=(ll)(m) ; i < (ll) (n) ; i++ )
#define rep(i,n) REP(i,0,n)
#define m_p(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define p_b push_back
#define SZ(x) ((int)(x).size) //size()がunsignedなのでエラー避けに


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

//Union-Find 
//0-indexed 注意！！
struct UnionFind {
  //data[idx]はノードの「根」もしくは「親」を格納している（必ずしも根ではない！）
  //  Q. 「根」じゃないの？
  //  初めは「根」を入れてるのだが、別のところでuniteが起きると情報が古くなる。
  //  だからfind_root()で再帰的に求めないと間違いが起こり得る。
  //  ちなみに「根」ノードのdata[idx]は直接アクセスしてok（最後にuniteされたものなので）
  vector< int > data;
 
  UnionFind(int sz) {
    data.assign(sz, -1); //ノードが属する根の番号を格納（根の場合はマイナス要素数を格納）
  }
 
  //併合　成功したらtrue, 既に同じ木ならfalse
  bool unite(int x, int y) {
    x = find_root(x), y = find_root(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  bool isSameGroup(int x, int y){
    x = find_root(x), y = find_root(y);
    if(x == y) return true;
    else return false;
  }
 
  //ノードが属する根の番号を返す（引数が根だった場合はその番号をそのまま帰す）
  int find_root(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find_root(data[k]));
  }
 
  //ノードが属する木に属するノードの数を返す
  int count(int k) {
    return (-data[find_root(k)]);
  }

  //木の数（接続していないグラフの数）を返す
  //根となっているノード（data[k]が負のもの）を数えるだけ
  int count_trees() {
    int ans = 0;
    for (int each_d : data){
      if (each_d < 0){
        ans += 1;
      }
    }
    return ans;
  }
};


// --------- library end - //


int main(){


  ll N = il();
  ll M = il();

  vector<pair<ll, ll> > ABs;

  rep(i, M){
    ll a = il() - 1;
    ll b = il() - 1;
    ABs.p_b(m_p(a, b));
  }

  ll ans = 0;
  rep(i, M){
    // i 番目の辺を採用しない
    UnionFind UF(N); //Nはノード数
    rep(j, M){
      if (i==j) continue;
      UF.unite(ABs[j].first, ABs[j].second);
    }
    if (UF.count_trees()!=1) ans++;
  }

  cout << ans << endl;



  
}