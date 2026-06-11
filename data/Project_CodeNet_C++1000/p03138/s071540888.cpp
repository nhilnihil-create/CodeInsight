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


// 10^18まではいけるようだが、10^19でオーバーフローする
// MODをつけたい場合もこれでもいい
// 繰り返し二乗法を使っているので O(logN) で計算できる
ll llpow(ll x, ll n){
  ll ans = 1;
  while (n > 0){
    if (n % 2 == 1) ans = ans * x; // % MOD; (MODつけたい場合のコピー用)
    x = x * x; // % MOD; (MODつけたい場合のコピー用)
    n /= 2; // n を右に1つビットシフト
  }
  return ans;
}

// --------- library end - //


int main(){

  ll N, K;
  cin >> N >> K;

  vector<ll> as;
  rep(i, N){
    as.push_back(il());
  }

  // 10^12は2進数で40桁くらいなので、45桁あるものとして考える

  // 45桁を、上から0～44桁目とする
  // turns[d] := A1～AN が、"上から" d桁目を何回ひっくり返すか
  vector<ll> turns(45, 0);
  for (ll a : as){
    rep(d, 45){
      if (a & (1LL << d)){
        // "下から" d 桁目のbitが立っていれば
        turns[44-d]++;
      }
    }
  }

  // dp[d : 0~44][smaller : 0|1] := 上からd桁目まで見て未満[でない|である]時の、現時点の桁部分までの f の最大値
  // dp[][] = -1 のとき、そのようなXの決め方は存在しないことを示す（つまりKを超えてしまっている）。dp[][0]には-1はありえない（未満でないということは、Kと等しいということなので）から、dp[][0]は0以上になっていく（ようにする）
  vector<vector<ll> > dp(45, vector<ll>(2, -1));


  // d : 0~44 桁目を上から順番に見ていく

  rep(d, 45){
    // 見やすくする＆定数倍高速化のための前計算
    ll beki = llpow(2, 44-d);
    ll mask = (1LL << (44-d));

    // 0桁目は手作業で入れる
    // kの0桁目が0なら、0にするしかない
    // kの1桁目が1なら、0と1を選べる
    if (d==0){
      if (K & mask){
        // Kの1桁目が1
        dp[d][0] = (N-turns[d]) * beki; // 未満でない = 1 を選んだ
        dp[d][1] = turns[d] * beki; // 未満である = 0 を選んだ
      }
      else{
        // Kの1桁目が0
        dp[d][0] = turns[d] * beki; // 未満でない=ピッタリ
        dp[d][1] = -1; // つまり変更なし
      }
    }
    else{
      // 1桁目以降～
      if (dp[d-1][1] == -1 && !(K & mask)){
        // まだ0が一度も出てきていなく、今回もKのbitが立っていない
        dp[d][0] = dp[d-1][0] + turns[d] * beki; // 未満でない=ピッタリ=bitを立てない
        dp[d][1] = -1; // つまり変更なし
      }
      else if (dp[d-1][1] == -1 && (K & mask)){
        // はじめてKのd桁目のbitが立った
        dp[d][0] = dp[d-1][0] + (N-turns[d]) * beki; // 未満でない=ピッタリ=bitを立てる
        dp[d][1] = turns[d] * beki; // 未満である = bitを立てない
      }
      else if (!(K & mask)){
        // 今までにbitが立ったことがあり、今回はKのbitが立っていない
        dp[d][0] = dp[d-1][0] + turns[d] * beki; // 未満でない=ピッタリ=bitを立てない
        dp[d][1] = dp[d-1][1] + max(turns[d] * beki, (N-turns[d]) * beki); // 未満である=前回の時点で未満でない場合(dp[d-1][0])からは取れない（今回で未満にできないから）。前回の時点で未満になっていたところからなら、自由に取れる（今回立てても立てなくてもいい）
      }
      else if (K & mask){
        // 今までにbitが立ったことがあり、今回もKのbitが立った
        dp[d][0] = dp[d-1][0] + (N-turns[d]) * beki; // 未満でない=ピッタリ=bitを立てる
        dp[d][1] = max(dp[d-1][0] + turns[d] * beki , max(dp[d-1][1] + (N-turns[d]) * beki , dp[d-1][1] + turns[d] * beki ) ); // 未満である=前回の時点で未満でない場合から取ってbitを立てないか、前回の時点で未満になっていたところから自由に取るか。よって3択となる
      }
    }
  }

  cout << max(dp[44][0], dp[44][1]) << endl;



}