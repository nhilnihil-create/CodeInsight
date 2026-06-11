#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr ll mod = 1e9 + 7;

template <typename T> inline bool chmax(T &a, const T b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> inline bool chmin(T &a, const T b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

const int Match[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int n, m, a[9], dp[20000];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        dp[i] = -1e9;
    for(int i = 0; i < m; i++)
        cin >> a[i];
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            int x = Match[a[j]];
            chmax(dp[i + x], dp[i] + 1);
        }
    }
    sort(a, a + m, greater<int>());
    int x = dp[n];
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < m; j++) {
            if(n - Match[a[j]] >= 0 && dp[n - Match[a[j]]] + 1 == dp[n]) {
                n -= Match[a[j]];
                cout << a[j];
                break;
            }
        }
    }
    cout << endl;
}