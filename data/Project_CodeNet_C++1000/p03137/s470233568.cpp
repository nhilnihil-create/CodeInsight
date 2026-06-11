#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

constexpr long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vll a(m);
    rep(i, m) cin >> a[i];

    if (n >= m) {
        cout << 0 << endl;
    } else {
        sort(a.begin(), a.end());

        vll b;
        rep(i, m - 1) {
            b.emplace_back(a[i + 1]-a[i]);
        }

        sort(b.begin(), b.end(), greater<ll>());

        ll sum = 0;
        rep(i, n - 1) {
            sum += b[i];
        }

        cout << a[m - 1] - a[0] - sum << endl;
    }
}