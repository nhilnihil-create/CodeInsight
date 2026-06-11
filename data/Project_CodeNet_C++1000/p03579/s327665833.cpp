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
const ll inf = 1e18;

#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define REP_FROM(i, j, n) for (ll i = (j); i < (n); ++i)
#define all(x) (x).begin(),(x).end()

ll power(ll base, ll exponent){ if(exponent % 2){ return power(base, exponent - 1) * base % mod; }else if(exponent){ ll root_ans = power(base, exponent / 2); return root_ans * root_ans % mod; }else{ return 1; }}
ll inverse(ll x){ return power(x, mod - 2);}
ll gcd(ll a, ll b) {if(a < b) gcd(b, a);ll r;while(r=a%b) {a=b;b=r;}return b;}
template<typename T> ll sum(T begin, T end) {return accumulate(begin, end, 0ll);}
struct combination{ vector<ll> fact, inv; combination(int sz) : fact(sz + 1), inv(sz + 1){ fact[0] = 1; for(int i = 1; i <= sz; i++){ fact[i] = fact[i - 1] * i % mod; } inv[sz] = power(fact[sz], mod - 2); for(int i = sz - 1; i >= 0; i--){ inv[i] = inv[i + 1] * (i + 1) % mod; } } ll C(int p, int q) const{ if(q < 0 || p < q) return 0; return (fact[p] * inv[q] % mod * inv[p - q] % mod); } };

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
ll cnt[2] = {};

vector<vector<bool>> used;

void dfs(int c, int r, const vector<vector<int>>& to) {
  used[c][r] = true;
  cnt[r]++;
  // cout << c << ":" << r << endl;
  for(const auto next: to[c]) {
    if(used[next][r^1]) continue;
    dfs(next, r^1, to);
  }
}

signed main() {
  ios::sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  used = vector<vector<bool>>(n, vector<bool>(2, false));
  vector<vector<int>> to(n);
  REP(i, m) {
    int a, b;
    cin >> a >> b;
    a--;b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  dfs(0, 0, to);
  if(used[0][0] && used[0][1]) {
    cout << n * (n - 1) / 2 - m << endl;
  }
  else {
    cout << cnt[0] * cnt[1] - m << endl;
  }
  return 0;
}
