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


  ll A, B, Q;
  cin >> A >> B >> Q;

  vector<ll> ss;
  ss.push_back(-1000000000000LL);
  rep(i, A){
    ss.push_back(il());
  }
  ss.push_back(1000000000000LL);

  vector<ll> ts;
  ts.push_back(-1000000000000LL);
  rep(i, B){
    ts.push_back(il());
  }
  ts.push_back(1000000000000LL);

  // 各クエリの処理
  // 番兵のせいで途中で変な値になるが、いつか正しい値になるのでOK
  // ∵ 制約から、答えは最大でも1.5*10^10くらいなので
  rep(q, Q){
    ll ans = LINF;

    ll x = il();

    // ss, ts のうち x 以上であるもののうち もっとも小さいものの idx (0-indexed)
    // 番兵を入れたので、それが「無い」場合は無い
    ll s_bigger_idx = lower_bound(begin_end(ss), x) - ss.begin();
    ll t_bigger_idx = lower_bound(begin_end(ts), x) - ts.begin();

    // ss, ts のうち x 未満であるもののうち、もっとも大きいものの idx (0-indexed)
    // 番兵を入れたので、それが「無い」場合は無い
    ll s_smaller_idx = s_bigger_idx - 1;
    ll t_smaller_idx = t_bigger_idx - 1;

    // 4 パターンを全探索

    // x から 右側にしかいかない（x自体を含む）
    chmin(ans, max(ss[s_bigger_idx], ts[t_bigger_idx]) - x);

    // x から 左側にしかいかない
    chmin(ans, x - min(ss[s_smaller_idx], ts[t_smaller_idx]));

    // 左側にあるs, 右側にあるtにいく
    ll tmpmin = min(abs(ss[s_smaller_idx] - x), abs(ts[t_bigger_idx] - x));
    ll tmpmax = max(abs(ss[s_smaller_idx] - x), abs(ts[t_bigger_idx] - x));
    chmin(ans, tmpmax + tmpmin * 2);
    
    // 左側にあるt, 右側にあるsにいく
    tmpmin = min(abs(ts[t_smaller_idx] - x), abs(ss[s_bigger_idx] - x));
    tmpmax = max(abs(ts[t_smaller_idx] - x), abs(ss[s_bigger_idx] - x));
    chmin(ans, tmpmax + tmpmin * 2);

    cout << ans << endk;
  }

}