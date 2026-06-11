#include <bits/stdc++.h>
template<int mod>
class Combination {
    std::vector<long long> fact, finv, inv;
public:
    Combination(int sz) {
        fact.resize(sz);
        finv.resize(sz);
        inv.resize(sz);
        fact[0] = 1;
        for(int i=1;i<sz;++i) {
            fact[i] = fact[i-1] * i % mod;
        }
        inv[0] = 0;
        inv[1] = 1;
        for(int i=2;i<sz;++i) {
            inv[i] = mod - inv[mod%i] * (mod/i) % mod;
        }
        finv[0] = 1;
        for(int i=1;i<sz;++i) {
            finv[i] = finv[i-1] * inv[i] % mod;
        }
    }
    long long C(long long n, long long k) {
        if(n < k) return 0;
        if(n < 0 || k < 0) return 0;
        return (fact[n] * finv[k] % mod) * finv[n-k] % mod;
    }
    long long P(long long n, long long k) {
        if(n < k) return 0;
        if(n < 0 || k < 0) return 0;
        return fact[n] * finv[n-k] % mod;
    }
    long long H(long long n, long long k) {
        return this->C(n + k - 1, k);
    }
    long long getfact(int i) {
        return fact[i];
    }
    long long getinv(int i) {
        return inv[i];
    }
};
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const double eps = 1e-10;
const int MOD = 998244353;
const int INF = 1000000000;
const ll LINF = 1ll<<50;
template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}
int main() {
  cin.tie(0);
  cout << fixed << setprecision(10);
  ll n, a, b, k; cin >> n >> a >> b >> k;
  Combination<MOD> comb(300010);
  ll ans = 0;
  for(int i=0;i<=n;++i) {
    if((k - i*a) % b != 0) continue;
    ll j = (k - i*a) / b;
    if(i > n || j > n) continue;
    ans += comb.C(n, i) * comb.C(n, j) % MOD;
    ans %= MOD;
  }
  cout << ans << endl;
}
