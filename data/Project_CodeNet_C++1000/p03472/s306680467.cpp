/**
 *    author:  FromDihPout
 *    created: 2020-08-11
**/

#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, h;
    cin >> n >> h;
    vector<int> b(n);
    int a = -1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x >> b[i];
        a = max(a, x);
    }
    sort(all(b));
    
    long long ans = 0;
    for (int i = n-1; i >= 0; i--) {
        if (h <= 0 || b[i] <= a) break;
        h -= b[i];
        ans++;
    }
    
    if (h > 0) {
        ans += h / a + (h % a != 0);
    }
    cout << ans << '\n';
    return 0;
}