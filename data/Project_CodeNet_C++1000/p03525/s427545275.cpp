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
#define begin_end(a) a.begin(),a.end() //sort(begin_end(vec));
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

  ll N;
  cin >> N;

  // buckets[d] := 差が d となる都市が 高橋くんの都市以外に いくつあるか
  vector<ll> g_buckets(13, 0);

  rep(i, N){
    g_buckets[il()]++;
  }

  // まず、差 0 が1人でもいたらNG。また、差 12 は2人いるとNG
  // それ以外は、3人以上いるとNG
  ll ngflag = false;
  if (g_buckets[0] >= 1) ngflag = true;
  else if (g_buckets[12] >= 2) ngflag = true;
  rep(i, 13) if (g_buckets[i] >= 3) ngflag = true;
  if (ngflag){
    cout << 0 << endk;
    return 0;
  }

  // 差 1 ~ 11 について、「1つしか無いなら、d時とする(0)か、24-d時とする(1)か」でbit全探索
  // N個の要素 {0, 1, ..., n-1} の部分集合の全探索
  ll ans = 1;
  // 各都市が、0~23時のそれぞれどこにいるか
  vector<ll> c_buckets(24, 0);
  c_buckets[0] = 1; // 高橋くん
  c_buckets[12] = g_buckets[12]; // 差12がいるかどうか
  for (ll bit = 0; bit < (1<<11); ++bit){
    rep(i, 11){
      // i = 0 ~ 10, d = 1 ~ 11
      ll d = i + 1; // i=0 のとき、差 d = i+1 = 1 を表す
      if (g_buckets[d] == 2){
        c_buckets[d] = 1;
        c_buckets[24-d] = 1;
      }
      else if (g_buckets[d] == 1){
        if (bit & (1<<i)){  // i番目のbitがtrueか
          c_buckets[24-d] = 1;
          c_buckets[d] = 0;
        }
        else{
          c_buckets[24-d] = 0;
          c_buckets[d] = 1;
        }
      }
      else{
        // 差dの都市が無い
        c_buckets[d] = 0;
        c_buckets[24-d] = 0;
      }
    }
    // s の計算
    ll tmp = 1;
    ll tmpans = INF;
    // 0 には絶対に高橋くんがいる
    // i : 0 ~ 23 について、i+1 に人がいるかどうか
    rep(i, 24){
      if (c_buckets[(i+1)%24] == 0) tmp++;
      else{
        chmin(tmpans, tmp);
        tmp = 1;
      }
    }
    chmax(ans, tmpans);
  }

  cout << ans << endk;

}