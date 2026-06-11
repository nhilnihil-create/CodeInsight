#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)

int main() {
    ll N, M, C;
    cin >> N >> M >> C;

    ll B[M];
    REP(i, M) cin >> B[i];

    ll ans = 0;
    REP(i, N) {
        ll sum = C;
        REP(j, M) {
            ll tmp;
            cin >> tmp;
            sum += tmp*B[j];
        }

        if(sum > 0) ans++;
    }

    cout << ans << endl;

    return 0;
}