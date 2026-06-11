#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    ll a[n];
    rep(i, n) cin >> a[i];
    sort(a, a + n);

    ll maxv = a[n - 1];
    double half = maxv / 2.0;
    auto iter = lower_bound(a, a + n, half);
    int idx = distance(a, iter);

    ll r = a[idx];
    double error = abs(half - r);
    if (idx - 1 >= 0 && error > abs(half - a[idx - 1])) r = a[idx - 1];
    if (idx + 1 < n && error > abs(half - a[idx + 1])) r = a[idx + 1];
    if (r == maxv) r = a[idx - 1];

    cout << maxv << ' ' << r << endl;
    return 0;
}
