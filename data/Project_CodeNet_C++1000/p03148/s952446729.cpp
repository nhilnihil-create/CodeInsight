#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const long long INF = 1LL<<40;


int main()
{
    ll N, K; cin >> N >> K;
    vvll s(N);
    rep(i, N) {
        ll t, d; cin >> t >> d; --t;
        s[t].push_back(d);
    }

    for (auto &v : s) {
        sort(all(v), greater<ll>());
        if (v.empty()) v.push_back(-INF);
    }

    sort(all(s), [&](vll a, vll b){return a[0] > b[0];});

    ll cur = 0;
    priority_queue<ll> que;
    rep(i, K) {
        cur += s[i][0];
        for (int j = 1; j < s[i].size(); ++j) que.push(s[i][j]);
    }
    for (int i = K; i < N; i++) rep(j, s[i].size()) que.push(s[i][j]);

    ll res = cur + K * K;
    for (ll x = K - 1; x >= 1; --x) {
        ll v = s[x][0];
        ll w = que.top();
        if (v < w) {
            que.pop(); cur += w;
            que.push(v); cur -= v;
        }
        res = max(res, cur + x * x);
    }
    cout << res << endl;
    return 0;
}