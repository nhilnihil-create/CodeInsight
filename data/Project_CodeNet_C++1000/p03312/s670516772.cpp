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

    int N;
    cin >> N;

    vi vals(N);
    vll pref(N + 1);

    for (int i = 0; i < N; i++) {
        cin >> vals[i];
        pref[i + 1] = pref[i] + vals[i];
    }

    ll ans = LLONG_MAX;
    for (int sp = 2; sp <= N - 2; sp++) {
        ll left = pref[sp], right = pref[N] - pref[sp];

        ll ldiff = LLONG_MAX;
        {
            int inx = lower_bound(all(pref), (left + 1) / 2) - pref.begin() - 1;
            if (inx > 0) ldiff = min(ldiff, abs(2 * pref[inx] - left));
            if (inx < sp - 1) ldiff = min(ldiff, abs(2 * pref[inx + 1] - left));
        }

        ll rdiff = LLONG_MAX;
        {
            int inx = lower_bound(all(pref), left + ((right + 1) / 2)) - pref.begin() - 1;
            if (inx > sp) rdiff = min(rdiff, abs(2 * (pref[inx] - left) - right));
            if (inx < N - 1) rdiff = min(rdiff, abs(2 * (pref[inx + 1] - left) - right));
        }

        ll diff = max(ldiff, rdiff);
        diff = max(diff, abs((left - ldiff) / 2 - (right + rdiff) / 2));
        diff = max(diff, abs((left + ldiff) / 2 - (right - rdiff) / 2));
        ans = min(ans, diff);
    }


    cout << ans << endl;

    return 0;
}

