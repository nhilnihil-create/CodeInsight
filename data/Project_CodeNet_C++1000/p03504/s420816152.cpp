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
    vll s(N), t(N), c(N);
    rep(i, N) cin >> s[i] >> t[i] >> c[i], c[i]--;

    vvll imos(C, vll(1e5 + 10));
    vvll tv_program(C, vll(1e5 + 10));

    rep(i, N) {
        imos[c[i]][s[i]]++;
        imos[c[i]][t[i]]--;
    }

    rep(i, C) rep(j, 1e5+5) {
        if (j == 0) tv_program[i][j] = imos[i][j];
        else tv_program[i][j] = tv_program[i][j-1] + imos[i][j];
    }

    rep(i, C) rep(j, 1e5+5) {
        if (tv_program[i][j] == 0 && tv_program[i][j+1]) tv_program[i][j] = 1;
    }

    ll maxn = 0;
    rep(j, 1e5+5) {
        ll total = 0;
        rep(i, C) {
            total += tv_program[i][j];
        }
        maxn = max(total, maxn);
    }
    cout << maxn << endl;
    return 0;
}