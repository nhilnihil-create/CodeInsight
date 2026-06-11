#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MOD (long long)(1e9+7)
#define INF (1LL<<60)
#define rep(i,n) for(ll i = 0; i < (n); i++)
#define rep1(i,n) for(ll i = 1; i <= (n); i++)

template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}


// 最大公約数
ll gcd(ll a, ll b)
{
  if(b == 0) return a;
  return gcd(b, a % b);
}

// mod m におけるa の逆元
ll modinv(ll a, ll m) {
  ll b = m, u = 1, v = 0;
  while (b) {
    ll t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}

// 素因数分解
vector<pair<ll, ll>> prim;
void pf(ll n)
{
  ll s = sqrt(n);
  ll r = 0;
  for(ll i = 2; i <= s; i++) {
    if((n % i) == 0) {
      r = 0;
      do {
	r++;
	n = n / i;
      } while((n % i) == 0);
      prim.push_back({i, r});
    }
  }
  if(n > s) {
    prim.push_back({n, 1});
  }
}

void solve()
{
  ll N; cin >> N;
  // ll x, y, z; cin >> x >> y >> z;
  // ll a, b, c; cin >> a >> b >> c;
  
  vector<ll> a1(N); rep(i, N) cin >> a1[i];
  vector<ll> a2(N); rep(i, N) cin >> a2[i];
  ll ans = 0;
  // bool ok = false;

  vector<ll> s1(N), s2(N);
  s1[0] = a1[0];
  s2[N - 1] = a2[N - 1]; 
  rep1(i, N - 1) {
    s1[i] = s1[i - 1] + a1[i];
    s2[N - 1 - i] = s2[N - i] + a2[N - 1 - i];
  }
  /*
  rep(i, N) cout << s1[i] << " ";
  cout << endl;
  rep(i, N) cout << s2[i] << " ";
  cout << endl;
  */
  
  rep(i, N) {
    ll s = s1[i] + s2[i];
    chmax(ans, s);
  }
  cout << ans << endl;
  // cout << (ok?"Yes":"No") << endl;
}


int main(void)
{
  // ll t; cin >> t; REP(i, t)
  solve();
}
