#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();

//==================================

int N;
Vl B;
Vl csum;

ll fun(ll b) {
    int idx = lower_bound(B.begin(), B.end(), b) - B.begin();
    ll res = b * (idx * 2 - N) + csum[N] - csum[idx] * 2;
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    B.resize(N);
    csum.resize(N + 1);
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        B[i] = a - (i + 1);
    }
    sort(B.begin(), B.end());
    for (int i = 0; i < N; i++) {
        csum[i + 1] = csum[i] + B[i];
    }

    ll t0, t1, t2, t3;
    t0 = -1e9, t3 = 1e9;
    while (t3 - t0 > 2) {
        t1 = (t0 * 2 + t3) / 3;
        t2 = (t0 + t3 * 2) / 3;

        ll f1 = fun(t1);
        ll f2 = fun(t2);

        if (f1 <= f2) {
            t3 = t2;
        }
        else {
            t0 = t1;
        }
    }

    cout << min(fun(t0), min(fun(t0 + 1), fun(t0 + 2))) << endl;

    return 0;
}