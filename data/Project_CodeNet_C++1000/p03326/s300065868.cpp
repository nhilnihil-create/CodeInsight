#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
#define INF 1000000000000000000
typedef pair<ll, ll> pll;
typedef pair<int, int> pint;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<ll>> v(N, vector<ll>(3));
    rep(i, N) {
        rep(j, 3) { cin >> v[i][j]; }
    }

    ll ans = 0;

    for (int bit = 0; bit < (1 << 3); bit++) {
        vector<int> a;
        for (int j = 0; j < 3; j++) {
            if (bit & (1 << j))
                a.push_back(j);
        }

        vector<vector<ll>> copy = v;
        vector<ll> can;
        ll tmp = 0;

        rep(i, N) {
            ll c = 0;
            rep(j, 3) {
                if (count(all(a), j) == 0)
                    c += v[i][j];
                else
                    c -= v[i][j];
            }
            can.push_back(c);
        }

        sort(all(can), greater<ll>());
        for (int i = 0; i < M; i++) {
            tmp += can[i];
        }

        ans = max(ans, tmp);
    }

    cout << ans << endl;
    return 0;
}