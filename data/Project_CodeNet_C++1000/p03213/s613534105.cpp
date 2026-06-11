#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define inf 1e9
#define INF 1000000000000000000

vector<pair<long long, long long>> prime_factorize(long long N) {
    vector<pair<long long, long long>> res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0)
            continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1)
        res.push_back({N, 1});
    return res;
}

int main() {
    int N;
    cin >> N;
    vector<ll> count(N + 1, 0);
    for (int i = 2; i < N + 1; i++) {
        vector<pair<ll, ll>> pri = prime_factorize(i);
        rep(k, pri.size()) { count[pri[k].first] += pri[k].second; }
    }

    ll over2 = 0, over4 = 0, over14 = 0, over24 = 0, over74 = 0;

    rep(i, N + 1) {
        if (count[i] >= 2)
            over2++;
        if (count[i] >= 4)
            over4++;
        if (count[i] >= 14)
            over14++;
        if (count[i] >= 24)
            over24++;
        if (count[i] >= 74)
            over74++;
    }

    ll ans = (over4 * (over4 - 1) * (over2 - 2)) / 2 + (over2 - 1) * over24 +
             (over4 - 1) * over14 + over74;
    cout << ans << endl;
}