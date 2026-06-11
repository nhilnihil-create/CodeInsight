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

// 文字列形式の実数（35.47, 5, -2.999 など）を、整数に置き換える
// その際、10^decimal_digit(小数部の桁数上限) を掛けて返す
// decimal_digit := 入力される実数における 小数部の桁数の上限
ll realstr_toll(string str, ll decimal_digit){
  if (str.find('.') == string::npos){
    // 元々整数だった場合 : str *= 10^decimal_digit
    str += string(decimal_digit, '0');
  }
  else{
    // 小数部を含む場合 : str *= 10^(decimal_digit - 入力された実数の小数部の桁数)
    ll decim = str.length() - str.find('.') - 1;
    str += string(decimal_digit - decim, '0');
    // . を消去
    str = regex_replace(str, regex("\\."), "");
  }
  return stoll(str);
}


// --------- library end - //


int main(){

  ll N = il();
  vector<ld> ps;
  rep(i, N){
    ps.push_back(ld(realstr_toll(is(), 2)) / ld(100));
  }

  // dp[i][o] := コインiまでを投げたとき、表がo回出る確率
  vector<vector<ld> > dp(N, vector<ld>(N+1, 0) );
  dp[0][0] = ld(1) - ps[0];
  dp[0][1] = ps[0];

  REP(i, 1, N){
    // i : 1 ~ N-1
    // 配るdp
    rep(j, N){
      // j : 0 ~ N-1（最大N回出るので、j+1がNに辿り着くようにする）
      // 表が出る
      dp[i][j+1] += dp[i-1][j] * ps[i];
      // 裏が出る
      dp[i][j] += dp[i-1][j] * (ld(1) - ps[i]);
    }
  }

  // dp[N-1][N]から、o > N - o である限り足す
  ld ans = 0;
  for (int o = N; o > N - o; o--){
    ans += dp[N-1][o];
  }

  od_nosp(ans); br();


}