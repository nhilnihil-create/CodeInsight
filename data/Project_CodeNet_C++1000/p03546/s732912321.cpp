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
    ll H, W; cin >> H >> W;
    vvll c(10, vll(10));
    rep(i, 10) rep(j, 10) cin >> c[i][j];
    vvll A(H, vll(W));
    rep(i, H) rep(j, W) cin >> A[i][j];
    rep(k, 10) rep(i, 10) rep(j, 10) c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
    ll cost = 0;
    rep(i, H) rep(j, W) if (A[i][j] != -1) cost += c[A[i][j]][1];
    cout << cost << endl;

    return 0;
}