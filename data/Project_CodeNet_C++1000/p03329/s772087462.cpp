#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;
template <class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
const long long INF = 1LL << 60;

int main() {
    ll N;
    cin >> N;
    vector<ll> dp(N + 1, INF);
    dp[0] = 0;
    for (ll i = 1; i <= N; i++) {
        ll power = 1;
        while (power <= i) {
            chmin(dp[i], dp[i - power] + 1);
            power *= 6;
        }
        power = 1;
        while (power <= i) {
            chmin(dp[i], dp[i - power] + 1);
            power *= 9;
        }
    }
    cout << dp[N] << endl;
    return 0;
}
