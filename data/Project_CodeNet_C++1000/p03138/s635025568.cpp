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
  // dp[][] = -1 のとき、そのようなXの決め方は存在しないことを意味する（つまりKを超えてしまっている）。dp[][0]には-1はありえない（未満でないということは、Kと等しいということなので）から、dp[][0]は0以上になっていく（ようにする）
  vector<vector<ll> > dp(45, vector<ll>(2, -1));

  // 0桁目（番兵）を設定
  // 0桁目はKもA1~ANもbitが立っていることがありえない桁（番兵。～3桁目くらいまで全部番兵）なので、必ず「未満でない」であり、「未満である」は無い。また、「未満でない」場合のfの最大値は0（値が無いので）。
  dp[0][0] = 0;
  dp[0][1] = -1; 

  // d : 1~44 桁目を上から順番に見ていく
  REP(d, 1, 45){
    // 見やすくする＆定数倍高速化のための前計算
    ll mask = (1LL << (44-d)); // (1<<k)=2^k なので、maskを2^(44-d)としても利用

    // exact -> exact
    // （少なくとも今回の問題では）どんな場合でもexactは構成できる（常にdp[d][0]>=0）ので、if (dp[d][0] != -1) は必要無い（と思われる）
    // Kのd桁目が立っていれば、Xのd桁目も立てないといけない
    //          立っていなければ、選択の余地は無い（立てないことしかできない）
    if (K & mask) dp[d][0] = dp[d-1][0] + (N-turns[d]) * mask;
    else dp[d][0] = dp[d-1][0] + turns[d] * mask;

    // exact -> smaller
    // e->e と同様、if (dp[d][0] != -1) は必要無い（と思われる）
    // Kのd桁目が立っていれば、Xのd桁目を立てなければいい
    //          立っていなければ、smallerにすることはできない
    if (K & mask) dp[d][1] = dp[d-1][0] + turns[d] * mask;

    // smaller -> smaller
    // 前の桁でsmallerを構成できていないといけないので、その判定が必要
    //  - smallerが構成できていなかったなら、何もしなくていい（初期値の-1のままになるか、e->s で遷移済みなら、その値になる）
    if (dp[d-1][1] != -1){
      // Kのd桁目が立っていてもいなくても、Xのd桁目は自由に選ぶことができる
      // e->s でdp[d][1] を一度更新している場合があるので、代入でなくchmax
      chmax(dp[d][1], dp[d-1][1] + max(turns[d] * mask, (N-turns[d]) * mask));
    }

  }

  cout << max(dp[44][0], dp[44][1]) << endl;



}