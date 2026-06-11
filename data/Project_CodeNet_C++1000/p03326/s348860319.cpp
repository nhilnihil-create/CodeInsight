#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    ll dx[8] = {1, 1, 1, 1, -1, -1, -1, -1};
    ll dy[8] = {1, -1, -1, 1, 1, 1, -1, -1};
    ll dz[8] = {1, 1, -1, -1, 1, -1, 1, -1};

    vector<ll> x(N), y(N), z(N);

    rep(i, N) { cin >> x[i] >> y[i] >> z[i]; }

    ll ans = 0;
    rep(i, 8) {
        vector<ll> sums;
        rep(j, N) {
            ll temp = x[j] * dx[i] + y[j] * dy[i] + z[j] * dz[i];
            sums.push_back(temp);
        }

        sort(all(sums), greater<ll>());
        ll can = accumulate(sums.begin(), sums.begin() + M, (ll)0);
        ans = max(ans, can);
    }

    cout << ans << endl;
}