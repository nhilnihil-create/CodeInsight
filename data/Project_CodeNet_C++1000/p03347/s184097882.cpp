#include <bits/stdc++.h>

#define int long long

using namespace std;


const int MAXN = 200 * 1000 + 23;









int n, a[MAXN], ans;


int32_t main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    if (a[0] != 0) return cout << -1, 0;
    for (int i = 1; i < n; i++)
        if (a[i] - a[i - 1] > 1)
            return cout << -1, 0;
        else
            ans += (a[i] != a[i - 1] + 1? a[i]: 1);
    cout << ans;
    return 0;
}