#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep1(i, n) for (int i = 1; i <= n; ++i)

int main() {
    int n, t, a, h, ans = 2147483647, cnt;
    cin >> n >> t >> a;
    for (int i = 0; i < n; ++i) {
        cin >> h;
        int d = abs((1000 * t - 6 * h) - 1000 * a);
        if (d < ans) {
            ans = d;
            cnt = i + 1;
        }
    }
    cout << cnt << endl;
    return 0;
}