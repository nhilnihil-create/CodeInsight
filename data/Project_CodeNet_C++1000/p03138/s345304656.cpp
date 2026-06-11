#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    ll N, K; cin >> N >> K;
    vector<ll> A(N);
    REP(i, 0, N) cin >> A[i];

    int cnt[60] = {};
    REP(i, 0, N) {
        ll tmp = A[i];
        REP(j, 0, 60) {
            cnt[j] += tmp & 1;
            tmp >>= 1;
        }
    }

    ll ans = 0, k = 0;
    for (int i = 59; i >= 0; i--) {
        // cout << "# i : " << i << ", cnt : " << cnt[i] << endl;
        if (cnt[i] >= N - cnt[i]) {
            ans += cnt[i] * (1LL << i);
        } else {
            if (k + (1LL << i) <= K) {
                ans += (N - cnt[i]) * (1LL << i);
                k += (1LL << i);
            } else {
                ans += cnt[i] * (1LL << i);
            }
        }
    }
    cout << ans << endl;
    return 0;
}