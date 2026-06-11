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
using Graph = vector<vector<pair<ll, ll>>>;


int main()
{
    ll N, C; cin >> N >> C;
    vvll D(C, vll(C));
    // cost to make i -> j
    rep(i, C) rep(j, C) {
        cin >> D[i][j];
    }
    vvll c(N, vll(N));
    rep(i, N) rep(j, N) {
        cin >> c[i][j]; c[i][j]--;
    }

    vvll counter(3, vll(C));

    rep(color, C) {
        // すべての色をcolorにするときにかかるコストを(i + j) % 3で分類して格納する
        rep(i, N) rep(j, N) {
            counter[(i + j + 2) % 3][color] += D[c[i][j]][color];
        }
    }

    ll minn = inf;
    rep(i, C) {
        rep(j, C) {
            if (i == j) continue;
            rep(k, C) {
                if (k == i || k == j) continue;
                minn = min(minn, counter[0][i] + counter[1][j] + counter[2][k]);
            }
        }
    }
    cout << minn << endl;
    return 0;
}