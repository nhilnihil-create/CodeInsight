#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll mod = 1000000007;
const double eps = 1e-8;

#ifdef DEBUG
#include "inc/debug.hpp"
#else
#define debug(...) 42
#endif

int main() {
    int N;
    cin >> N;
    vector<ll> L(N), R(N);
    for (int i = 0; i < N; ++i) cin >> L[i] >> R[i];
    sort(L.rbegin(), L.rend());
    sort(R.begin(), R.end());

    ll mx = max(0LL, -2 * R[0]);
    ll k = 0;
    for (int i = 0; i < N; ++i) {
        k += 2 * L[i];
        mx = max({mx, k, k - 2 * R[i]});
        if (i+1 < N) mx = max(mx, k - 2 * (R[i] + R[i+1]));
        k -= 2 * R[i];
    }
    cout << mx << endl;

    return 0;
}