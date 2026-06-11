#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, a[maxn];

int main() {
    cin >> n; a[0] = -1;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] - a[i - 1] > 1) { cout << -1 << endl; exit(0); }
        if (i == 1) continue;
        if (a[i] == a[i - 1] + 1) ans++;
        else ans += a[i];
    }
    cout << ans << endl;
    return 0;
}