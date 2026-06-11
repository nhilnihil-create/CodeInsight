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

    ll cnt[60] = {};
    REP(i, 0, N) {
        ll tmp = A[i];
        REP(j, 0, 60) {
            cnt[j] += tmp & 1;
            tmp >>= 1;
        }
    }

    ll sum[61] = {};
    REP(i, 1, 61) {
        sum[i] = sum[i - 1] + (1LL << (i - 1)) * max(cnt[i - 1], N - cnt[i - 1]);
    }

    // REP(i, 0, 10) cout << sum[i] << " ";
    // cout << endl;

    ll ans = 0, cur = 0;
    for (int i = 59; i >= 0; i--) {
        if (K & (1LL << i)) {
            ans = max(ans, cur + cnt[i] * (1LL << i) + sum[i]);
            cur += (1LL << i) * (N - cnt[i]);
        } else {
            cur += (1LL << i) * cnt[i];
        }
    }
    ans = max(ans, cur);

    cout << ans << endl;
    return 0;
}