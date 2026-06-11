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

ll dx[] = {-1, 0, 1 , 0};
ll dy[] = {0, -1, 0 , 1};


ll bfs(ll H, ll W, vector<string> s)
{
  ll cnt = -1;
  vector<ll> seen(H * W, -1);
  queue<ll> que;
  que.push(0);
  seen[0] = 0;
  while(que.size() > 0) {
    ll p = que.front(); que.pop();
    ll x = p % W;
    ll y = p / W;
    if(x == W - 1 && y == H - 1) {
      cnt = seen[y * W + x];
      break;
    }
    ll nx, ny;
    rep(i, 4){
      nx = x + dx[i];
      ny = y + dy[i];
      if(nx >= 0 && nx < W && ny >= 0 && ny < H) {
	if(s[ny][nx] == '.' && seen[ny * W + nx] < 0) {
	  seen[ny * W + nx] = seen[y * W + x] + 1;
	  que.push(ny * W + nx);
	}
      }
    }
  }
  
  return cnt;
}


void solve()
{
  ll H,W; cin >> H >> W;
  vector<string> s(H); rep(i, H) cin >> s[i];
  ll ans = -1;
  ll fcnt = 0;
  rep(y, H) rep(x, W) {
    if(s[y][x] == '.') fcnt ++;
  }
  
  ans = bfs(H, W, s);
  if(ans >= 0) {
    ans = fcnt - ans - 1;
  }
  cout << ans << endl;
}


int main(void)
{
  // ll t; cin >> t; rep(i, t)
  solve();
}
