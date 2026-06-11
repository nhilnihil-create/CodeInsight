#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define ALL(a) a.begin(), a.end()
ll dx[4] = { 0, 1, 0, -1 };
ll dy[4] = { 1, 0, -1, 0 };
const ll INF = 1l << 40;
const ll MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll N, K;
    cin >> N >> K;
    vector<vector<ll>> s(N); // s[種類]={おいしさ}
    rep(i, N)
    {
        ll t, d;
        cin >> t >> d;
        t--;
        s[t].push_back(d);
    }

    for (auto& v : s) {
        sort(v.rbegin(), v.rend());
        if (v.empty()) {
            v.push_back(-INF); // 番兵
        }
    }

    // sort(s.rbegin(), s.rend());
    // 「美味しさの最大値」の大きいネタ順
    sort(s.begin(), s.end(), [&](vector<long long> a, vector<long long> b) { return a[0] > b[0]; });

    ll cur = 0;
    priority_queue<ll> que; // sushiを全て入れる
    for (int i = 0; i < K; i++) { // とりあえずK個sushiを食う
        cur += s[i][0]; // 現在の値
        for (int j = 1; j < s[i].size(); j++) {
            que.push(s[i][j]);
        }
    }
    for (int i = K; i < N; i++) {
        for (int j = 0; j < s[i].size(); j++) {
            que.push(s[i][j]);
        }
    }

    ll res = cur + K * K; // 求めるスコア
    for (ll x = K - 1; x >= 1; x--) { // 種類を変える
        ll v = s[x][0]; // 今curに加えられている値
        ll w = que.top(); // priority_queueの上からの値
        if (v < w) {
            que.pop();
            cur += w;
            que.push(v);
            cur -= v;
        }
        res = max(res, cur + x * x);
    }
    cout << res << endl;

    return 0;
}