#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld  = long double;
using pll = pair<ll, ll> ;
using pld = pair<ld, ld>;
const int INF=1e9+7;
const ll LINF=1LL<<60 ;
const ll MOD=998244353 ; //10e9+7から今回は998244353に
const ld PI=acos(-1);
const ld EPS = 1e-9; //微調整用（EPSより小さいと0と判定など）
 
#define gcd __gcd //llは受け取ってくれない
int lcm(int a, int b){return a / gcd(a, b) * b;}
#define ALL(a) a.begin(),a.end() //sort(ALL(vec));
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define PB push_back
#define SZ(x) ((int)(x).size) //size()がunsignedなのでエラー避けに
 
//最大値、最小値を更新する。aよりbのが大きい（小さい）か等しければaを更新してtrueを返す。そうでなければ何もせずfalseを返す chmax(nowmax,x);
template<typename T>
bool chmax(T& a, T b){return (a = max(a, b)) == b;}
template<typename T>
bool chmin(T& a, T b){return (a = min(a, b)) == b;}
// ----- template end ---- //
 
// ------- library ------- //


//nCk(mod MOD)の計算　n!(mod MOD)とk!^{MOD-2}を前計算して求める
//nの最大値を設定すること
ll maxN = 300000; // n, kの最大値を代入(0 < n <= maxN)
vector<ll> fac(maxN+1); //n!(mod MOD) を格納。
vector<ll> ifac(maxN+1); //k!^{MOD-2} (mod MOD)
//a,bの範囲的にこれだけ配列を用意していけば十分

ll mpow(ll x, ll n){ //x^n(mod MOD) ←普通にpow(x,n)では溢れてしまうため，随時mod計算
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % MOD;
        x = x*x % MOD;
        n = n >> 1;
    }
    return ans;
}

ll comb(ll a, ll b){ //aCbをmod計算
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    ll tmp = ifac[a-b]* ifac[b] % MOD;
    return tmp * fac[a] % MOD;
}

// ----- library end ----- //



int main() {
  
  ll N, A, B, K;
  cin >> N >> A >> B >> K;

  //大した量ではないので，先にfax[i]とifax[i]を全て計算しておく
  fac[0] = 1;
  ifac[0] = 1;
  for(ll i = 0; i<maxN; i++){
      fac[i+1] = fac[i]*(i+1) % MOD; // n!(mod MOD)
      ifac[i+1] = ifac[i]*mpow(i+1, MOD-2) % MOD; // k!^{MOD-2} (mod MOD) ←累乗にmpowを採用
  }

  vector<pair<ll, ll> > colorlist;
  ll restK;
  REP(r, 0, min(N, K/A) + 1){ //r:0～K/R ただしrがNを超えてはならない
    restK = K - r * A;
    if (restK==0){
      colorlist.PB(make_pair(r, 0));
      break;
    }
    else if (restK % B == 0){
      if(N >= restK/B){
        colorlist.PB(make_pair(r,restK/B));
      }
    }
  }

  ll ans = 0;
  ll tmpans = 0;
  for (auto eacht : colorlist){
    ll rr, gg;
    tie(rr, gg) = eacht;
    tmpans = comb(N, rr) * comb(N, gg) % MOD;
    ans += tmpans;
    ans %= MOD;
//    cout << ans << ' ' << rr << ' ' << gg << ' ' << bb << ' ' << ww << endl;
  }

  cout << ans << endl;


// -- main() end -- //
}


 