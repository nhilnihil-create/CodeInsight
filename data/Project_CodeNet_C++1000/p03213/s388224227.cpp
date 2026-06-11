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

vector<pair<ll, ll> > prime_factorize(ll N) {
  vector<pair<ll, ll> > res;
  for (ll a = 2; a * a <= N; ++a) {
    // 2～floor(√N)までが素因数の候補
    // なお、aが合成数となる場合もあるが、Nから既に約数として取り出されているため自然と無視され、素因数だけが入っていく。例えばa=4は合成数だが、a=2の時に割られているため、約数として判定されない。
    if (N % a != 0) continue;
    // ここから先、aはNの約数
    ll ex = 0;
    while (N % a == 0) {
      // aがNの約数でなくなるまで、aで割っていく
      // 約数でなくすのに要した回数が、素因数aの指数
      // ex) 約数として8があったのなら、2の約数でなくすのに3回要する = 2^3
        ++ex;
        N /= a;
    }
    res.push_back({a, ex}); // {素因数, 指数}
  }
  // この時点で、Nは、√N以下の素因数aを全部ふるい出した状態になっている
  // まだN>1だとすると、それは√N以上の素因数があった場合か、元々のN自身が素数だった場合なので、ともかく現時点のNを素因数に加える
  if (N != 1) res.push_back({N, 1});
  return res;
}

ll comb(ll n, ll k){
  if (n < k) return 0;
  if (k > n / 2) k = n - k;
  ll ret = 1;
  ll divider = 1;
  rep(i, k) ret *= (n - i);
  rep(i, k) divider *= (i + 1);
  return ret / divider;
}

// --------- library end - //


int main(){

  ll N = il();

  // 1 ~ N の素因数分解をし、各素因数毎に出てきた数を数える
  vector<ll> pfac_buckets(100, 0);

  REP(i, 2, N+1){
    for (pll pf : prime_factorize(i)){
      // <素因数, 指数>
      pfac_buckets[pf.first] += pf.second;
    }
  }

  // 74回以上出てきた素因数の種類数
  ll over_74 = 0;
  // 24回以上出てきた素因数の種類数
  ll over_24 = 0;
  // 14回以上出てきた素因数の種類数
  ll over_14 = 0;
  // 4回以上出てきた素因数の種類数
  ll over_4 = 0;
  // 2回以上出てきた素因数の種類数
  ll over_2 = 0;

  rep(i, 100){
    ll cnt = pfac_buckets[i];
    if (cnt >= 2) over_2++;
    if (cnt >= 4) over_4++;
    if (cnt >= 14) over_14++;
    if (cnt >= 24) over_24++;
    if (cnt >= 74) over_74++;
  }

  // 七五数としてありえるのは、p, q, r を異なる素数として、
  // p^74, p^24*q^2, p^14*q^4, p^4*q^4*r^2 のみ
  ll ans = 0;
  ans += over_74;

  ans += comb(over_24, 2) * 2; // まず、over_24だけから2つとる組み合わせ どっちを^24にして、どっちを^2にするかで、*2
  ans += (over_2 - over_24) * over_24; // 次に、2~23 から1つと、24~から1つとる組み合わせ

  ans += comb(over_14, 2) * 2; // まず、over_24だけから2つとる組み合わせ どっちを^14にして、どっちを^4にするかで、*2
  ans += (over_4 - over_14) * over_14; // 次に、2~23 から1つと、24~から1つとる組み合わせ

  ans += comb(over_4, 3) * 3; // まず、over_4だけから3つとる組み合わせ どれを^2にするかで、*3
  ans += comb(over_4, 2) * (over_2 - over_4); // 次に、2~3から1つと、4~から2つとる組み合わせ

  cout << ans << endl;

}