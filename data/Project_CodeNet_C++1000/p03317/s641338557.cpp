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

    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i];

    if ((n - 1) % (k - 1) == 0) {
        cout << (n - 1) / (k - 1) << endl;
    } else {
        cout << (n - 1) / (k - 1) + 1 << endl;
    }
}