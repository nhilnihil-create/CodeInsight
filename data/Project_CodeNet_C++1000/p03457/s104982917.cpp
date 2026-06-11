#include <bits/stdc++.h>
using namespace std;
using ll         = long long;
constexpr ll MOD = 1000000007;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define REP2(i, x, n) for (ll i = x; i < (n); i++)
const long long INF = numeric_limits<long long>::max();
int main() {
    ll N;
    cin >> N;
    ll time = 0;
    ll x    = 0;
    ll y    = 0;
    for (ll i = 0; i < N; ++i) {
        ll t, a, b;
        cin >> t >> a >> b;
        ll td   = t - time;
        ll diff = abs(a - x) + abs(b - y);
#ifdef SOURCE_TEST
        cout << "diff:" << diff << ",td:" << td << "\n";
#endif
        if (diff > td) {
            cout << "No"
                 << "\n";
            return 0;
        } else {
            ll d = diff - td;
#ifdef SOURCE_TEST
            cout << d << "\n";
#endif
            if ((d % 2) != 0) {
                cout << "No"
                     << "\n";
                return 0;
            }
        }
        time = t;
        x    = a;
        y    = b;
    }
    cout << "Yes"
         << "\n";

    return 0;
}