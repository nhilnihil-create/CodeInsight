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
const ld EPS = 1e-9; //微調整用（EPSより小さいと0と判定など）

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

#define gcd __gcd //llは受け取らない C++17~のgcdと違うので注意
int lcm(int a, int b){return a / gcd(a, b) * b;}
#define begin_end(a) a.begin(),a.end() //sort(begin_end(vec));
#define REP(i,m,n) for(ll i=(ll)(m) ; i < (ll) (n) ; i++ )
#define rep(i,n) REP(i,0,n)
#define m_p(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define p_b push_back
#define SZ(x) ((int)(x).size) //size()がunsignedなのでエラー避けに

//4近傍（上下左右） rep(i, 2) にすると右・下だけに進む
vector<int> dx_4 = {1, 0, -1, 0};
vector<int> dy_4 = {0, 1, 0, -1};

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

// -------- template end - //


// - library ------------- //

  // エラトステネスの篩
  // O(N log(logN)) で isPrime[0～n]のvectorを返す
  // 普通の素数判定を使うと O(N √N) なので、N=1000000 くらいならこっちが安全
  // 使い方 : vector<bool> isPrime = Eratosthenes(n);
  // isPrime(0), isPrime(1) はもちろん false を返す
  // 「素数の数」を返したければ、return p; とすればいい
  // 「素数のリスト」を返したければ、return primes; とすればいい（昇順sorted）
  vector<bool> Eratosthenes(ll n){
    vector<ll> primes;
    vector<bool> isPrime(n + 1, false);
    ll p = 0; // n 以下の素数の数
    REP(i, 2, n+1) isPrime[i] = true;
    REP(i, 2, n+1){
      if (isPrime[i]){
        p++;
        primes.push_back(i);
        for(ll j = 2*i; j <= n; j += i){
          isPrime[j] = false;
        }
      }
    }
    return isPrime;
  };

    vector<ll> Era(ll n){
    vector<ll> primes;
    vector<bool> isPrime(n + 1, false);
    ll p = 0; // n 以下の素数の数
    REP(i, 2, n+1) isPrime[i] = true;
    REP(i, 2, n+1){
      if (isPrime[i]){
        p++;
        primes.push_back(i);
        for(ll j = 2*i; j <= n; j += i){
          isPrime[j] = false;
        }
      }
    }
    return primes;
  };

// --------- library end - //


int main(){

  vector<bool> isPrime = Eratosthenes(100001);
  


  vector<ll> cumsum(100001, 0);
  REP(i, 1, 100001){
    cumsum[i] = cumsum[i-1];
    if (i % 2 == 1 && isPrime[i] && isPrime[(i+1)/2]) cumsum[i]++;
  }

  ll Q = il();
  rep(i, Q){
    ll l = il();
    ll r = il();
    cout << cumsum[r] - cumsum[l-1] << endl;
  }
  
}