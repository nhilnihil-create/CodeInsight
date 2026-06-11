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
    ll half = maxv / 2;
    auto iter = lower_bound(a, a + n, half);
    int idx = distance(a, iter);

    ll r = a[idx];
    if (idx - 1 >= 0 && abs(half - r) > abs(half - a[idx - 1])) r = a[idx - 1];
    if (r == maxv) r = a[idx - 1];

    cout << maxv << ' ' << r << endl;
    return 0;
}
