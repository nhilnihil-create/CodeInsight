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
// int lcm(int a, int b){return a / gcd(a, b) * b;}
#define begin_end(a) a.begin(),a.end() //sort(begin_end(vec));
#define REP(i,m,n) for(ll i=(ll)(m) ; i < (ll)(n) ; i++ )
#define DREP(i,m,n) for(ll i=(ll)(m) ; i > (ll)(n) ; i-- )
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



// --------- library end - //


int main(){

  ll H, W, D;
  cin >> H >> W >> D;
  
  // table[m 余り][q 商] := (Ahw = q*D + m) であるような (h, w)
  // 表の行数は最大でfloor(H*W/D)+1 なので、その領域を最初に確保する
  // 余計な領域があってもいい（クエリの正当性が保証されているため、ゴミデータがあってもアクセスしなくて済むから問題無い）
  vector<vector<pll> > table(D, vector<pll>(H*W/D + 1, m_p(0, 0)) );

  // table[0][0] := (0, 0) のままにしておく
  // ここの値は何でもいい（結局、最後の計算で差し引かれるため）
  rep(h, H) rep(w, W){
    ll a = il();
    ll m = a % D;
    ll q = a / D;
    table[m][q].first = h + 1;
    table[m][q].second = w + 1;
  }

  // 累積和の前計算
  // cumsum[m][q] := m mod D を最初から1つずつ辿ってq*D+mにたどり着くまでの魔力
  vector<vector<ll> > cumsum(D, vector<ll>() );
  rep(a, H*W+1){
    ll m = a % D;
    ll q = a / D;
    if (q == 0){
      cumsum[m].p_b(0);
    }
    else{
      ll distance = abs(table[m][q].first - table[m][q-1].first) + abs(table[m][q].second - table[m][q-1].second);
      cumsum[m].p_b( cumsum[m][q-1] +  distance);
    }
  }

  // クエリの処理
  ll Q = il();
  rep(i, Q){
    ll l = il();
    ll r = il();
    ll lm = l % D;
    ll lq = l / D;
    ll rm = r % D;
    ll rq = r / D;

    // l==r である場合の処理は必要無い。どっちにしろ答えは0となるので
    cout << cumsum[rm][rq] - cumsum[lm][lq] << endl;
  }
  
}