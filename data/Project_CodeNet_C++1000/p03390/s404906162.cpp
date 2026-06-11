#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll find_nth(ll a, ll k) {
    if (k < a) return k;
    return k + 1;
}

ll prod_max(ll M, ll a, ll b) {
    vll tryA = { a - 1, a + 1 };
    for (ll i = M/2 - 5; i <= M/2 + 5; i++)
        tryA.push_back(i);

    ll res = 0;
    for (ll ar : tryA) if (ar != a) {
        ll wp = ar < a ? ar : ar - 1;
        if (wp > 0 && wp <= M) {
            ll br = find_nth(b, M + 1 - wp);
            res = max(res, ar * br);
        }
    }

    return res;
}

void solve() {
    int A, B;
    cin >> A >> B;

    ll T = ll(A) * B;

    ll ans = 0, lo = 1, hi = A + B;
    while (lo <= hi) {
        ll mi = (lo + hi) / 2;
        if (prod_max(mi, A, B) < T) {
            ans = mi;
            lo = mi + 1;
        } else {
            hi = mi - 1;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        solve();
    }

    return 0;
}

