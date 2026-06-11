#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;
typedef pair<int, int> pint;

int main() {
    int N;
    cin >> N;
    ll MOD = pow(10, 9) + 7;
    vector<int> C(N);
    vector<vector<int>> places(210000);
    vector<ll> dp(210000);
    int prev = -1;
    rep(i, N) { cin >> C[i]; }

    for (int i = 0; i < 210000; i++) {
        places[i].clear();
    }

    for (int i = 0; i < N; i++) {
        places[C[i]].push_back(i);
    }

    // dp
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        dp[i] += dp[i - 1];
        dp[i] %= MOD;

        int c = C[i - 1];
        int it = lower_bound(places[c].begin(), places[c].end(), i - 1) -
                 places[c].begin();

        if (it > 0) {
            int j = places[c][it - 1];
            if ((i - 1) - j > 1)
                dp[i] += dp[j + 1], dp[i] %= MOD;
        }
    }

    cout << dp[N] << endl;
}
