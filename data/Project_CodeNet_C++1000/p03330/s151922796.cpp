#include <bits/stdc++.h>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define rep(i, n) repd(i, 0, n)

using namespace std;

using ll = long long;
using ul = unsigned long long;
ll mod = 1000000007;

int main() {
    ll n, c;
    cin >> n >> c;
    ll d[c][c];
    rep(i, c) {
        rep(j, c) { cin >> d[i][j]; }
    }

    ll memo[3][c];
    rep(i, 3) {
        rep(j, c) { memo[i][j] = 0; }
    }

    rep(i, n) {
        rep(j, n) {
            ll color;
            cin >> color;
            color--;
            ll index = (i + j) % 3;
            memo[index][color]++;
        }
    }

    ll ans = mod * mod;
    rep(c0, c) {
        rep(c1, c) {
            rep(c2, c) {
                if (c0 == c1 || c1 == c2 || c0 == c2)
                    continue;
                ll temp = 0;
                rep(num, c) { temp += memo[0][num] * d[num][c0]; }
                rep(num, c) { temp += memo[1][num] * d[num][c1]; }
                rep(num, c) { temp += memo[2][num] * d[num][c2]; }
                // cout << c0 << " " << c1 << " " << c2 << ":" << temp << endl;
                ans = min(ans, temp);
            }
        }
    }

    cout << ans << endl;
}

