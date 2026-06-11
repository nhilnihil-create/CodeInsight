#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> p_ll;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
#define repr(i,from,to) for (ll i=(ll)from; i<(ll)to; i++)
#define all(vec) vec.begin(), vec.end()
#define rep(i,N) repr(i,0,N)
#define per(i,N) for (int i=(int)N-1; i>=0; i--)

const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

vector<ll> fac;
void c_fac(int x=pow(10,6)+10) { fac.resize(x,true); rep(i,x) fac[i] = i ? (fac[i-1]*i)%MOD : 1; }
ll inv(ll a, ll m=MOD) { ll b = m, x = 1, y = 0; while (b!=0) { int d = a/b; a -= b*d; swap(a,b); x -= y*d; swap(x,y); } return (x+m)%m; }
ll nck(ll n, ll k) { return fac[n]*inv(fac[k]*fac[n-k]%MOD)%MOD; }
ll gcd(ll a, ll b) { if (a<b) swap(a,b); return b==0 ? a : gcd(b, a%b); }
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }

struct range { ll l, r, i; };

int main() {
  ll N; cin >> N;
  vector<range> ra(N); rep(i,N) { cin >> ra[i].l >> ra[i].r; ra[i].i = i; }
  vector<range> ra_l = ra, ra_r = ra;
  sort(all(ra_l),[](const range &x, const range &y) { return x.r<y.r||(x.r==y.r&&x.l<y.l); } );
  sort(all(ra_r),[](const range &x, const range &y) { return x.l>y.l||(x.l==y.l&&x.r>y.r); } );
  
  // 左から始まるパターン
  ll res_l = 0, res_r = 0;
  ll np = 0, pl = 0, pr = 0;
  bool used[N] = {};
  rep(i,N) {
    if (i%2==0) {
      while (used[ra_l[pl].i]) pl++;
      used[ra_l[pl].i] = true;
      if (ra_l[pl].r>np) break;
      res_l += np - ra_l[pl].r;
      np = ra_l[pl].r;
    }
    else {
      while (used[ra_r[pr].i]) pr++;
      used[ra_r[pr].i] = true;
      if (ra_r[pr].l<np) break;
      res_l += ra_r[pr].l - np;
      np = ra_r[pr].l;
    }
  }
  res_l += abs(np);

  np = 0; pl = 0; pr = 0;
  fill_n(used,N,false);
  rep(i,N) {
    if (i%2==1) {
      while (used[ra_l[pl].i]) pl++;
      used[ra_l[pl].i] = true;
      if (ra_l[pl].r>np) break;
      res_r += np - ra_l[pl].r;
      np = ra_l[pl].r;
    }
    else {
      while (used[ra_r[pr].i]) pr++;
      used[ra_r[pr].i] = true;
      if (ra_r[pr].l<np) break;
      res_r += ra_r[pr].l - np;
      np = ra_r[pr].l;
    }
  }
  res_r += abs(np);

  ll result = max(res_l, res_r);
  cout << result << endl;
  return 0;
}