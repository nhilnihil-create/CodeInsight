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




signed main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  map<int, int> d;
  d[24] = 1;
  REP(i, n) {
    int x;
    cin >> x;
    if(d.count(x) > 0) {
      d[x]++;
    }
    else {
      d[x] = 1;
    }
  }
  if(d.count(0) > 0  || (d.count(12) ? d[12] :0) > 1) {
    cout << 0 << endl;
    return 0;
  }
  REP(i, 24) {
    // cout << (d.count(i) ? d[i] :0) << " ";
    if((d.count(i) ? d[i] :0) > 2) {
      cout << 0 << endl;
      return 0;
    }
  }
  // cout << endl;
  ll ans = 0;
  REP(i, 1<<24) {
    bool valid = true;
    if(d.count(0) == 0 && i % 2 == 1) {
      continue;
    }
    REP_FROM(j, 1, 12) {
      int cnt = (d.count(j) ? d[j] :0);
      bool lft = i & (1 << j);
      bool rgt = i & (1 << (24-j));
      if(cnt == 0 ) {
        if(lft || rgt) {
          valid = false;
          break;
        }
      }
      if(cnt == 1) {
        if(lft ^ rgt) {
        }
        else {
          valid = false;
          break;
        }
      }
      if(cnt > 1) {
        if(lft && rgt) {
        }
        else {
          valid = false;
          break;
        }
      }
    }
    {
      bool cnt = d.count(12);
      if((i & (1 << 12)) > 0 != cnt) {
        valid = false;
      }
    }
    if(valid) {
      ll tmp = 100;
      ll lft = 0;
      REP(j, 24) {
        if(i & 1 << j) {
          tmp = min(tmp, j - lft);
          lft = j;
        }
      }
      tmp = min(tmp, 24 - lft);
      // cout << bitset<64>(i) << endl;
      // cout << tmp << endl;
      ans = max(ans, tmp);
    }
  }
  cout << ans << endl;
  return 0;
}
