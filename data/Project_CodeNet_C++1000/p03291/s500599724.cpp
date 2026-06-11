#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl

const ll mod = 1000000007;

ll modpow(ll b, ll e) {
  if(e == 0) return 1LL;
  if(e % 2 == 1) return modpow(b, e - 1) * b % mod;
  ll m = modpow(b, e >> 1);
  return m * m % mod;
}

int main() {
  string s;
  cin >> s;

  int n = s.size();
  vector<int> la(n), lq(n), rc(n), rq(n);

  for(int i = 1; i < n; i++) {
    la[i] = la[i - 1], lq[i] = lq[i - 1];
    if(s[i - 1] == 'A') ++la[i];
    if(s[i - 1] == '?') ++lq[i];
  }
  for(int i = n - 2; i >= 0; i--) {
    rc[i] = rc[i + 1], rq[i] = rq[i + 1];
    if(s[i + 1] == 'C') ++rc[i];
    if(s[i + 1] == '?') ++rq[i];
  }

  ll ans = 0LL;
  rep(i, n) {
    if(s[i] == 'A' || s[i] == 'C') continue;

    ll ac = (modpow(3, lq[i]) * modpow(3, rq[i])) % mod;
    ac = (ac * la[i]) % mod;
    ac = (ac * rc[i]) % mod;
    ans = (ans + ac) % mod;

    if(rq[i] > 0) {
      ll aq =
        (modpow(3, lq[i]) * modpow(3, rq[i] - 1)) % mod;
      aq = (aq * la[i]) % mod;
      aq = (aq * rq[i]) % mod;
      ans = (ans + aq) % mod;
    }

    if(lq[i] > 0) {
      ll qc =
        (modpow(3, lq[i] - 1) * modpow(3, rq[i])) % mod;
      qc = (qc * lq[i]) % mod;
      qc = (qc * rc[i]) % mod;
      ans = (ans + qc) % mod;
    }

    if(lq[i] > 0 && rq[i] > 0) {
      ll qq =
        (modpow(3, lq[i] - 1) * modpow(3, rq[i] - 1)) % mod;
      qq = (qq * lq[i]) % mod;
      qq = (qq * rq[i]) % mod;
      ans = (ans + qq) % mod;
    }
  }
  cout << ans << endl;
  return 0;
}