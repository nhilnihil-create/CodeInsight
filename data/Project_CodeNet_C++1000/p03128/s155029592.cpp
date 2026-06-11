#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define reprr(i, m, n) for (ll i = m; i < n; i++)
#define inf 2e9
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;



int main()
{
    vll cost{0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    ll N, M; cin >> N >> M;
    vll A(M); rep(i, M) cin >> A[i];
    vll dp(N + 1, -inf);
    dp[0] = 0;
    for (ll i = 1; i <= N; i++) {
        for (ll a : A) {
            ll left = i - cost[a];
            if (left >= 0) dp[i] = max(dp[i], dp[left] + 1);
        }
    }
    //for (auto elem : dp) cout << elem << " "; cout << endl;

    sort(all(A), greater<ll>());
    //for (auto elem : A) cout << elem << " "; cout << endl;
    string ans = "";
    for (ll digit = dp[N]; digit > 0; digit--) {
        for (ll a : A) {
            if (N - cost[a] < 0) continue;
            if (dp[N] == dp[N - cost[a]] + 1) {
                N -= cost[a];
                ans += to_string(a);
                break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}