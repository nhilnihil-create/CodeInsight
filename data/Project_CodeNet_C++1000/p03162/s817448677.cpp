#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF = (1LL << 60) * (-1);

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}


int main()
{
    int n; cin >> n;
    int a[n+10][3];
    rep(i, n) rep(j, 3) cin >> a[i][j];
    ll dp[n+10][3] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (j != k) chmax(dp[i+1][k], dp[i][j] + a[i][k]);
            }
        }
    }
    ll ans = 0;
    rep(i, 3) chmax(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}