#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    ll x, y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // dp[何枚取ったか][次が先手=0, 後手=1]
    vector<vector<ll>> dp(n + 10, vector<ll>(2));
    for(int i = n - 1; i >= 0; i--) {
        dp[i][0] = -1;
        ll pre = (i == 0 ? y : a[i - 1]);
        chmax(dp[i][0], llabs(pre - a[n - 1]));
        for(int j = i + 1; j < n; j++) {
            chmax(dp[i][0], dp[j][1]);
        }
        dp[i][1] = LLINF;
        pre = (i == 0 ? x : a[i - 1]);
        chmin(dp[i][1], llabs(pre - a[n - 1]));
        for(int j = i + 1; j < n; j++) {
            chmin(dp[i][1], dp[j][0]);
        }
    }
    cout << dp[0][0] << endl;
}