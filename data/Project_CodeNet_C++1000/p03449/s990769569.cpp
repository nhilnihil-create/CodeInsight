#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
ll const INF = 1LL << 60;
ll const MAX_N = 510000;
ll const MOD = 1000000007;

int main() {
    ll N;
    cin >> N;
    vector<ll> a1(N);
    vector<ll> a2(N);
    rep(i, N) cin >> a1[i];
    rep(i, N) cin >> a2[i];

    vector<ll> a1_sum(N, 0);
    vector<ll> a2_sum(N, 0);

    a1_sum[0] = a1[0];
    for (ll i = 1; i < N; i++) {
        a1_sum[i] += a1_sum[i - 1] + a1[i];
    }

    a2_sum[N - 1] = a2[N - 1];
    for (ll i = N - 2; i >= 0; i--) {
        a2_sum[i] += a2_sum[i + 1] + a2[i];
    }

    ll ans = 0;
    rep(i, N) { ans = max(ans, a1_sum[i] + a2_sum[i]); }

    cout << ans << endl;

    return 0;
}
