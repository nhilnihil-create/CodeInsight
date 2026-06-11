#include "bits/stdc++.h"

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] <= x) {
            x -= a[i];
            ++ans;
        }
    }
    if (ans < n - 1)
        cout << ans << endl;
    else if (x == a[n - 1])
        cout << n << endl;
    else
        cout << n - 1 << endl;
}
