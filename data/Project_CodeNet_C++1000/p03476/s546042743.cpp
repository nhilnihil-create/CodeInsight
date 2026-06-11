#include <bits/stdc++.h>
using namespace std;
using ll         = long long;
constexpr ll MOD = 1000000007;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define REP2(i, x, n) for (ll i = x; i < (n); i++)
#define PR(x) cout << (x) << "\n"
#define PS(x) cout << (x) << " "
const long long INF = numeric_limits<long long>::max();

vector<ll> isPrimes;

vector<ll> sieve(ll N) {
    // エラトステネスのふるい
    // int N = 101010;くらい
    vector<ll> isPrimes(N + 1, 1);
    isPrimes[0] = 0;
    isPrimes[1] = 0;
    for (ll i = 2; pow(i, 2) <= N; i++) {
        if (isPrimes[i])
            for (ll j = 2; i * j <= N; j++) isPrimes[i * j] = 0;
    }
    return isPrimes;
}

bool isLike2017(ll N) {
    if (N % 2 == 0) return false;
    if (!isPrimes[N]) return false;
    return isPrimes[(N + 1) / 2];
}

void dumpVector(const vector<ll>& vec) {
#ifdef SOURCE_TEST
    for (ll i = 0; i < vec.size(); ++i) {
        cout << vec[i] << ",";
    }
    cout << endl;
#endif
}
int main() {
    isPrimes = sieve(1000000 + 100);
    dumpVector(isPrimes);
    ll MAX = 1000000 + 100;
    vector<ll> values(MAX, 0);
    REP(i, values.size()) {
        values[i] = isLike2017(i) ? 1 : 0;
    }
    dumpVector(values);

    vector<ll> sums(MAX + 1, 0);
    REP(i, values.size()) {
        sums[i + 1] = values[i] + sums[i];
    }
    dumpVector(sums);
    ll Q;
    cin >> Q;
    REP(i, Q) {
        ll l, r;
        cin >> l >> r;
        PR(sums[r + 1] - sums[l]);
    }
    return 0;
}