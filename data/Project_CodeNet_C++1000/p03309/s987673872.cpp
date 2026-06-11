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

ll fun(const Vl& B, ll b) {
    ll res = 0;
    for (const auto& bi : B) {
        res += abs(bi - b);
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    Vl B(N);
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        B[i] = a - (i + 1);
    }

    ll t0, t1, t2, t3;
    t0 = -1e9, t3 = 1e9;
    while (t3 - t0 > 2) {
        t1 = (t0 * 2 + t3) / 3;
        t2 = (t0 + t3 * 2) / 3;

        ll f1 = fun(B, t1);
        ll f2 = fun(B, t2);

        if (f1 <= f2) {
            t3 = t2;
        }
        else {
            t0 = t1;
        }
    }

    cout << min(fun(B, t0), min(fun(B, t0 + 1), fun(B, t0 + 2))) << endl;

    return 0;
}