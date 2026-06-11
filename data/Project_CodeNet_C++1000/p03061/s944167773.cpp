#include <bits/stdc++.h>
using namespace std;
using ll         = long long;
constexpr ll MOD = 1000000007;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define REP2(i, x, n) for (ll i = x; i < (n); i++)
#define PR(x) cout << (x) << "\n"
#define PS(x) cout << (x) << " "
const long long INF = numeric_limits<long long>::max();

ll GCD(ll a, ll b) {
    if (a > b) swap(a, b);
    while (b != 0) {
        ll c = b;
        ll d = a % b;
        a    = c;
        b    = d;
    }
    return a;
}

int main() {
    ll N;
    cin >> N;
    vector<ll> vec(N);

    vector<ll> L(N + 1, 0);
    vector<ll> R(N + 1, 0);

    REP(i, N) {
        cin >> vec[i];
        L[i + 1] = GCD(L[i], vec[i]);
    }

    for (ll i = N - 1; i >= 0; --i) {
        R[i] = GCD(R[i + 1], vec[i]);
    }

    ll ans = 0;
    REP(i, N) {
        ans = max(ans, GCD(L[i], R[i + 1]));
    }
    PR(ans);
    return 0;
}