#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N;
ll dp[100100];

int main() {
    cin >> N;
    vector<ll> v;
    v.push_back(1);

    int tmp = 6;
    while (tmp <= N) {
        v.push_back(tmp);
        tmp *= 6;
    }

    tmp = 9;
    while (tmp <= N) {
        v.push_back(tmp);
        tmp *= 9;
    }
    // rep(i, v.size()) cout << v[i] << " ";

    sort(v.begin(), v.end());
    rep(i, 100100) dp[i] = INF;

    dp[0] = 0;
    rep(i, v.size()) {
        for (int j = v[i]; j <= N; j++) {
            dp[j] = min(dp[j], dp[j - v[i]] + 1);
        }
    }
    cout << dp[N] << endl;
    // rep(i, v.size()) {
    //     cout << v[i] << " ";
    // }

}