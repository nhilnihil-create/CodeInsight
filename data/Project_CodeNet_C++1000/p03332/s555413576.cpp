#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> P;
const int mod =  998244353;
const int INF = 1e18;

struct Combination {
    vector<int64_t> fact, rfact;
    Combination(int sz) : fact(sz + 1), rfact(sz + 1) {
        fact[0] = 1;
        for(int i = 1; i < fact.size(); i++){
            fact[i] = fact[i - 1] * i % mod;
        }
        rfact[sz] = inv(fact[sz]);
        for(int i = sz - 1; i >= 0; i--){
            rfact[i] = rfact[i + 1] * (i + 1) % mod;
        }
    }
    int64_t inv(int x) const {
        return pow(x, mod - 2);
    }
    int64_t pow(int64_t x, int64_t n) const {
        int64_t ret = 1;
        while(n > 0){
            if(n & 1) (ret *= x) %= mod;
            (x *= x) %= mod;
            n >>= 1;
        }
        return (ret);
    }
    int64_t P(int n, int r) const {
        if(r < 0 || n < r) return (0);
        return (fact[n] * rfact[n - r] % mod);
    }

    int64_t C(int p, int q) const {
        if(q < 0 || p < q) return (0);
        return (fact[p] * rfact[q] % mod * rfact[p - q] % mod);
    }

    int64_t H(int n, int r) const {
        if(n < 0 || r < 0) return (0);
        return (r == 0 ? 1 : C(n + r - 1, r));
    }
};

signed main(){
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    int ans = 0;
    Combination cmb(n);
    for(int i = 0; i <= n; i++){
        int tmp = k - a * i;
        if(tmp % b != 0) continue;
        int j = tmp / b;
        if(j < 0) continue;
        ans += cmb.C(n, i) * cmb.C(n, j) % mod;
        ans %= mod;
    }
    cout << ans << endl;
}