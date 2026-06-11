#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, a, b;
    cin >> n >> a >> b;
    if (n + 1 < a + b || a * b < n) {
        cout << -1 << '\n';
        return 0;
    }
    vector<int> c(b, 1);
    c[0] = a;
    int sum = a + b - 1;
    for (int i = 1; i < b; i++) {
        if (sum < n) {
            c[i] += min(a - 1, n - sum);
            sum += c[i] - 1;
        }
    }
    vector<int> ans(n);
    int mx = n, pos = 0;
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < c[i]; j++) {
            ans[pos + j] = mx - c[i] + 1 + j;
        }
        mx -= c[i];
        pos += c[i];
    }
    for (int i : ans) {
        cout << i << " ";
    }
    cout << '\n';
    return 0;
}
