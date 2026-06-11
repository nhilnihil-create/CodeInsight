#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    vector<ll> a(N);
    rep(i, N) { cin >> a[i]; }

    vector<bool> dp(K + 1, false);
    for (int i = 0; i <= K; i++) {
        for (int j = 0; j < N; j++) {
            if (i - a[j] >= 0) {
                dp[i] = dp[i] || !dp[i - a[j]];
            }
        }
    }

    cout << (dp[K] ? "First" : "Second") << endl;
}