#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define reprr(i, m, n) for (ll i = m; i < n; i++)
#define inf 2e9
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;


int main()
{
    ll N, K; cin >> N >> K;
    vvll s(N);
    rep(i, N) {
        ll t, d; cin >> t >> d; t--;
        s[t].push_back(d);
    }

    rep(i, N) {
        if (s[i].empty()) s[i].push_back(-inf);
        sort(all(s[i]), greater<ll>());
    }

    sort(all(s), [&](vll a, vll b){return a[0] > b[0];});

    priority_queue<ll> que;
    ll cur = 0;
    rep(i, K) {
        cur += s[i][0];
        for (ll j = 1; j < s[i].size(); j++) que.push(s[i][j]);
    }

    reprr(i, K, N) {
        rep(j, s[i].size()) que.push(s[i][j]);
    }

    ll res = cur + K * K;

    for (ll x = K - 1; x >= 1; x--) {
        ll v = s[x][0];
        ll w = que.top();
        if (v < w) {
            cur -= v;
            cur += w;
            que.pop();
            que.push(v);
            res = max(res, cur + x * x);
        }
    }
    cout << res << endl;
    return 0;
}