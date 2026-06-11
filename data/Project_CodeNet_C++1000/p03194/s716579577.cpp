#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (int)(b); ++i)
#define FORR(i, a, b) for (int i = (a); i >= (int)(b); --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
typedef vector<P> VP;
typedef vector<PL> VPL;
typedef vector<string> VS;

VPL prime_factorize(ll n) {
    VPL res;  // first: prime, second: count
    for (ll p = 2; p * p <= n; p++) {
        if (n % p != 0) continue;
        int cnt = 0;
        while (n % p == 0) {
            cnt++;
            n /= p;
        }
        res.push_back(PL(p, cnt));
    }
    if (n != 1) res.push_back(PL(n, 1));
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, p;
    cin >> n >> p;
    VPL p_cnts = prime_factorize(p);
    ll ans = 1;
    for (auto p_cnt : p_cnts) REP(i, p_cnt.second / n) ans *= p_cnt.first;
    cout << ans << ln;
    return 0;
}
