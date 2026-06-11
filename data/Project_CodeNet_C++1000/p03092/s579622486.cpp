#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1e18;
//const ll mod = 1000000007;
ll dp[5005][5005];
ll N, A, B;
ll p[5000];

int main() {
    cin >> N >> A >> B;
    for(int i = 0; i < N; i++) {
        cin >> p[i];
    }
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            dp[i][j] = 1e18;
        }
    }
    dp[0][0] = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= N; j++) {
            if(p[i] < j) {
                chmin(dp[i+1][j], dp[i][j] + B);
            } else {
                chmin(dp[i+1][j], dp[i][j] + A);
                chmin(dp[i+1][p[i]], dp[i][j]);
            }
        }
    }
    ll ans = 1e18;
    for(int i = 0; i <= N; i++) {
        chmin(ans, dp[N][i]);
    }
    cout << ans << endl;
    return 0;
}
