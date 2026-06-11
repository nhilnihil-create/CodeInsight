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
  vector<ll> x(N), y(N), h(N); rep(i, N) cin >> x[i] >> y[i] >> h[i];
  
  ll cx, cy, H;
  
  rep(i, 101) {
    rep(j, 101) {
      ll H1 = -1;
      rep(k, N) {
	if(h[k] != 0) {
	  H1 = abs(x[k] - i) + abs(y[k] - j) + h[k];
	}
      }
      //      cerr << "[" << i << "," << j << "] " << H1 << endl;
      
      rep(k, N) {
	ll lh = max(H1 - abs(x[k] - i) - abs(y[k] - j), 0LL);
	if(lh != h[k]) {
	  H1 = -1;
	  break;
	}
      }
      if(H1 > 0) {
	cx = i;
	cy = j;
	H = H1;
      }
    }
  }
  
  cout << cx << " " << cy << " " << H << endl;
}


int main(void)
{
  // ll t; cin >> t; rep(i, t)
  solve();
}
