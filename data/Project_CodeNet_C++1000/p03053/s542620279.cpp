#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> p_ll;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
#define repr(i,from,to) for (ll i=(ll)from; i<(ll)to; i++)
#define all(vec) vec.begin(), vec.end()
#define rep(i,N) repr(i,0,N)
#define per(i,N) for (ll i=(ll)N-1; i>=0; i--)

const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const ll INF = pow(2,30)-1;

vector<ll> fac;
void c_fac(ll x=pow(10,6)+10) { fac.resize(x,true); rep(i,x) fac[i] = i ? (fac[i-1]*i)%MOD : 1; }
ll inv(ll a, ll m=MOD) { ll b = m, x = 1, y = 0; while (b!=0) { ll d = a/b; a -= b*d; swap(a,b); x -= y*d; swap(x,y); } return (x+m)%m; }
ll nck(ll n, ll k) { return fac[n]*inv(fac[k]*fac[n-k]%MOD)%MOD; }
ll modpow(ll x, ll p) { ll result = 1, now = 1, pm = x; while (now<=p) { if (p&now) { result = result * pm % MOD; } now*=2; pm = pm*pm % MOD; } return result; }
ll gcd(ll a, ll b) { if (a<b) swap(a,b); return b==0 ? a : gcd(b, a%b); }
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }

struct coord { ll x, y; };

int main() {
  ll H, W; cin >> H >> W;
  string A[H]; rep(i,H) cin >> A[i];
  vector<vector<ll>> turn(H, vector<ll>(W,-1));

  queue<coord> q;
  rep(i,H) rep(j,W) {
    if (A[i][j]=='#') {
      q.push({i,j});
      turn[i][j] = 0;
    }
  }

  coord to[4] = {{-1,0},{0,-1},{0,1},{1,0}};
  while (q.size()) {
    coord now = q.front(); q.pop();
    rep(i,4) {
      ll tox = now.x+to[i].x, toy = now.y+to[i].y;
      if (tox>=0&&tox<H) {
        if (toy>=0&&toy<W) {
          if (turn[tox][toy]==-1) {
            turn[tox][toy] = turn[now.x][now.y] + 1;
            q.push({tox,toy});
          }
        }
      }
    }
  }
  // rep(i,H) debug(all(turn[i]));

  ll result = 0; rep(i,H) rep(j,W) result = max(result,turn[i][j]);
  cout << result << endl;
  return 0;
}