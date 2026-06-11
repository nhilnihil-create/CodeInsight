#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B;
    cin >> N >> A >> B;

    vi vals(N), loc(N);
    for (int i = 0; i < N; i++) {
        cin >> vals[i];
        loc[vals[i] - 1] = i;
    }

    vvll dp(N + 1, vll(N + 1, LLONG_MAX));
    dp[0][0] = 0;

    auto put_min = [&](ll &a, ll b) {
        a = min(a, b);
    };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            if (dp[i][j] == LLONG_MAX) continue;

            if (loc[i] < j) {
                put_min(dp[i+1][j], dp[i][j] + A);
            } else if (loc[i] >= j) {
                put_min(dp[i+1][j], dp[i][j] + B);
                put_min(dp[i+1][loc[i]+1], dp[i][j]);
            }
        }
    }

    ll ans = LLONG_MAX;
    for (ll v : dp[N])
        ans = min(ans, v);
    cout << ans << endl;

    return 0;
}

