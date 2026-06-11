#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n, cnt = 0, ans = 0;
    cin >> n;
    if (n < 105) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 105; i <= n; i += 2) {
        cnt = 0;
        for (int j = 1; j <= i; ++j) {
            if (i % j == 0) {
                cnt++;
            }
        }
        if (cnt == 8)
            ans++;
    }
    cout << ans << endl;
}