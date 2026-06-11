#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define reprr(i, m, n) for (ll i = m; i < n; i++)
#define inf (1LL<<60)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
using Graph = vector<vector<pair<ll, ll>>>;

vll x, y, z;
ll N, M;

int main()
{
    cin >> N >> M;
    x.resize(N), y.resize(N), z.resize(N);
    rep(i, N) cin >> x[i] >> y[i] >> z[i];

    ll maxn = -inf;
    rep(i, 2) rep(j, 2) rep(k, 2) {
        priority_queue<pair<ll, vector<ll>>> que;
        rep(l, N) que.push(
            {
                (i == 0 ? 1 : -1) * x[l] + (j == 0 ? 1 : -1) * y[l] + (k == 0 ? 1 : -1) * z[l],
                {x[l], y[l], z[l]}
            }
        );

        ll x_sum = 0, y_sum = 0, z_sum = 0;
        rep(i, M) {
            //cout << que.top().first << ": " << endl;
            vll v = que.top().second; que.pop();
            //cout << v[0] << " " << v[1] << " " << v[2] << endl;
            x_sum += v[0], y_sum += v[1], z_sum += v[2];
        }
        //cout << endl;
        maxn = max(maxn, abs(x_sum) + abs(y_sum) + abs(z_sum));
    }
    cout << maxn << endl;

    return 0;
}