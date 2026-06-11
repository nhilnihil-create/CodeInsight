#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i, n) for (int i = 0; i < n; i++)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

int main() {
    int n, k;
    cin >> n >> k;
    ll x[n];
    rep (i, n) cin >> x[i];
    ll ans = INF;
    rep (i, n - k + 1) {
        ll sum = x[k + i - 1] - x[i];
        if (x[i] < 0) sum += min (abs (x[i]), abs (x[i + k - 1]));
        else
            sum += x[i];
        //cout << sum << "\n";
        ans = min (sum, ans);
    }

    cout << ans << "\n";
}