#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>

using namespace std;

using ll = long long;
const ll INF = 1LL << 40;

int main()
{
    ll N, K;
    cin >> N >> K;

    vector<vector<ll>> S(N);
    for (int i = 0; i < N; i++) {
        ll t, d;
        cin >> t >> d;
        S[t - 1].push_back(d);
    }

    for (auto &s : S) {
        sort(begin(s), end(s), greater<ll>());
        if (s.empty()) {
            s.push_back(-INF);
        }
    }

    sort(begin(S), end(S),
         [&](vector<ll> a, vector<ll> b) { return a[0] > b[0]; });

    ll cur = 0;
    priority_queue<ll> Q;
    for (int i = 0; i < K; i++) {
        cur += S[i][0];
        for (int j = 1; j < S[i].size(); j++) {
            Q.push(S[i][j]);
        }
    }
    for (int i = K; i < N; i++) {
        for (int j = 0; j < S[i].size(); j++) {
            Q.push(S[i][j]);
        }
    }

    ll res = cur + K * K;
    for (ll x = K - 1; x >= 1; x--) {
        ll v = S[x][0];
        ll w = Q.top();

        if (v < w) {
            Q.pop();
            cur += w;

            Q.push(v);
            cur -= v;
        }

        res = max(res, cur + x * x);
    }

    cout << res << '\n';
}
