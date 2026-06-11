#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep1(i, n) for (int i = 1; i <= n; ++i)

int main() {
    int n, x, sum = 0, cnt = 0;
    cin >> n >> x;
    int a[n];
    rep(i, n) { cin >> a[i]; }
    sort(a, a + n);
    rep(i, n) {
        x -= a[i];
        if (x >= 0) {
            cnt++;
        } else {
            break;
        }
    }
    if (x > 0)
        cnt--;
    cout << cnt << endl;
    return 0;
}