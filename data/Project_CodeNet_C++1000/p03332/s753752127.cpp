#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"

struct BinomialCoefficient {
    BinomialCoefficient() {}
    BinomialCoefficient(int n) : fac(n + 2), finv(n + 2), inv(n + 2) {
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i <= n; i++) {
            fac[i] = fac[i - 1] * i % mod;
            inv[i] = mod - inv[mod % i] * (mod / i) % mod;
            finv[i] = finv[i - 1] * inv[i] % mod;
        }
    }
    
    long long factorial(int n) {
        return fac[n];
    }
    
    long long combination(int n, int r) {
        if ((n < r) || (n < 0) || (r < 0)) return 0;
        return fac[n] * (finv[r] * finv[n - r] % mod) % mod;
    }
    
    long long permutation(int n, int r) {
        if ((n < r) || (n < 0) || (r < 0)) return 0;
        return fac[n] * finv[n - r] % mod;
    }
    
private:
    int mod = 998244353;
    vector<long long> fac, finv, inv;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    const ll mod = 998244353;
    ll n, a, b, k;
    cin >> n >> a >> b >> k;
    ll ans = 0;
    BinomialCoefficient bc(n);
    rep(acnt, n + 1) {
        ll rem = k - acnt * a;
        if (rem % b != 0) continue;
        ll bcnt = rem / b;
        if (bcnt > n) continue;
        ans = (ans + bc.combination(n, acnt) * bc.combination(n, bcnt)) % mod;
    }
    cout << ans << endl;
    return 0;
}
