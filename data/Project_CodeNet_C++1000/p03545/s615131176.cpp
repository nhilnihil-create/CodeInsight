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
  // ll N, K; cin >> N >> K;
  // ll x, y, z; cin >> x >> y >> z;
  ll a, b, c, d;
  string s; cin >> s;
  a = s[0] - '0';
  b = s[1] - '0';
  c = s[2] - '0';
  d = s[3] - '0';
  
  rep(i, 1<<3) {
    ll k = a;
    s = to_string(a);
    if(i & 1)  {
      s += '+';
      k += b;
    } else {
      s += '-';
      k -= b;
    }
    s += to_string(b);
    if(i>>1 & 1)  {
      s += '+';
      k += c;
    } else {
      s += '-';
      k -= c;
    }
    s += to_string(c);
    if(i>>2 & 1)  {
      s += '+';
      k += d;
    } else {
      s += '-';
      k -= d;
    }
    s += to_string(d);
    if(k == 7) {
      cout << s << "=7" << endl;
      return;
    }
    
  }
}


int main(void)
{
  // ll t; cin >> t; rep(i, t)
  solve();
}
