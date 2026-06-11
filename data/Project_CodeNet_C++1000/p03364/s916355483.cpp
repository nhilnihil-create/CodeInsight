#include <bits/stdc++.h>
using namespace std;

// types
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<ll> vll;

// macros
#define ALL(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define FI first
#define SE second
#define REP(i,n) for(int i=0;i<((int)n);i++)
#define REP1(i,n) for(int i=1;i<((int)n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define PB push_back
#define EB emplace_back
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL

// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double eps = 1e-10;
const int MOD = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

struct RollingHash{
  vll hash1, hash2;
  vll power1, power2;
  ll base1, base2;
  ll mod1, mod2;
  void Init(string s){
    ll n = s.size();
    hash1.assign(n+1, 0);
    hash2.assign(n+1, 0);
    power1.assign(n+1, 1);
    power2.assign(n+1, 1);
    base1 = 1007;
    base2 = 2009;
    mod1 = 1e9+7;
    mod2 = 1e9+9;

    REP(i, n){
      hash1[i+1] = (hash1[i]*base1+s[i])%mod1;
      hash2[i+1] = (hash2[i]*base2+s[i])%mod2;
      power1[i+1] = (power1[i]*base1)%mod1;
      power2[i+1] = (power2[i]*base2)%mod2;
    }
  }

  pll getHash(ll l, ll r){
    ll h1 = hash1[r]-hash1[l]*power1[r-l]%mod1;
    if(h1<0)
      h1 += mod1;
    ll h2 = hash2[r]-hash2[l]*power2[r-l]%mod2;
    if(h2<0)
      h2 += mod2;
    return {h1, h2};
  }
};


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin >> n;
  string s[n+1], t[n+1];
  REP(i, n){
    cin >> s[i];
    REP(j, n)
      t[j] += s[i][j];
  }

  RollingHash rh_v[303], rh_h[303];
  pll RS2[303][303], RT2[303][303];
  REP(i, n){
    s[i] += s[i];
    t[i] += t[i];
    rh_h[i].Init(s[i]);
    rh_v[i].Init(t[i]);
    REP(j, n){
      RS2[i][j] = rh_h[i].getHash(j, n+j);
      RT2[i][j] = rh_v[i].getHash(j, n+j);
    }

  }




  ll ans = 0;
  REP(a, n){
    REP(b, n){
      bool flag = true;
      REP(k, n){
        if(RS2[(a+k)%n][b] != RT2[(b+k)%n][a])
          flag = false;
      }

      if(flag)
        ans++;
    }
  }

  cout << ans << endl;
}
