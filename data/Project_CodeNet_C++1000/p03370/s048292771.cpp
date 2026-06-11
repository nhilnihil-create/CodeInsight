#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, ans = 0;
    cin >> n >> x;
    int a[n];
    for(int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a+n);
    for(int i = 0; i < n; ++i) {
        x -= a[i];
        if(x < 0) break;
        ans++;
    }
    if(x > 0) ans += x/a[0];
    cout << ans << '\n';
    return 0;
}
