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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    ll tot = 0;
    int bs = INT_MAX;

    vi a(N), b(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
        tot += a[i];

        if (a[i] > b[i]) {
            bs = min(bs, b[i]);
        }
    }

    if (a == b) { cout << 0 << endl; return 0; }

    ll ans = tot - bs;
    cout << ans << endl;

    return 0;
}

