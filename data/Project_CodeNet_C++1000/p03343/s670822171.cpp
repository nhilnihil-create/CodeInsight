#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <numeric>
#include <bitset>

using namespace std;
using ll = long long;
using ld = long double;
const ll mod =  1000000007;

#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define REP_FROM(i, j, n) for (ll i = (j); i < (n); ++i)
#define all(x) (x).begin(),(x).end()

ll power(ll base, ll exponent, ll module){ if(exponent % 2){ return power(base, exponent - 1, module) * base % module; }else if(exponent){ ll root_ans = power(base, exponent / 2, module); return root_ans * root_ans % module; }else{ return 1; }}
ll inverse(ll x){ return power(x, mod - 2, mod);}
ll gcd(ll a, ll b) {if(a < b) gcd(b, a);ll r;while(r=a%b) {a=b;b=r;}return b;}
struct combination{ vector<ll> fact, inv; combination(int sz) : fact(sz + 1), inv(sz + 1){ fact[0] = 1; for(int i = 1; i <= sz; i++){ fact[i] = fact[i - 1] * i % mod; } inv[sz] = power(fact[sz], mod - 2, mod); for(int i = sz - 1; i >= 0; i--){ inv[i] = inv[i + 1] * (i + 1) % mod; } } ll C(int p, int q) const{ if(q < 0 || p < q) return 0; return (fact[p] * inv[q] % mod * inv[p - q] % mod); } };

int bsearch(const vector<ll>& a, ll x){
  int lft = 0;
  int rgt = a.size();
  while (rgt - lft > 1) {
    int mid = (lft + rgt) / 2;
    if(a[mid] < x) {
      lft = mid;
    }
    else {
      rgt = mid;
    }
  }
  return lft;
}

using PQ = priority_queue<ll, vector<ll>, greater<ll>>;

signed main() {
  ios::sync_with_stdio(false);
  ll n, k, q;
  cin >> n >> k >> q;
  vector<ll> a(n);
  vector<ll> b(n);
  REP(i, n) cin >> a[i];
  REP(i, n) b[i] = a[i];
  PQ p;
  vector<ll> s;
  sort(all(b));
  ll ans = 1e9;
  REP(i, n - k + 1) {
    if(i > 0 && b[i-1] == b[i]) continue;
    p = PQ();
    s.clear();
    REP(j, n) {
      if(a[j] < b[i]) {
        while(p.size() >= k) {
          s.push_back(p.top());
          p.pop();
        }
        p = PQ();
      }
      else {
        p.push(a[j]);
      }
    }
    while(p.size() >= k) {
      s.push_back(p.top());
      p.pop();
    }
    if(s.size() < q) continue;
    sort(all(s));
    ans = min(ans, s[q-1] - s[0]);
  }
  cout << ans << endl;
  return 0;
}
