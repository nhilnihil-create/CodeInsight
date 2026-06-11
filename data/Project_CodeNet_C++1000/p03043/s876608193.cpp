#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int x;
    double ans = 0;
    for (int i = 1; i <= n; i++) {
        x = i;
        int cnt = 0;
        while (x < k) {
            x *= 2;
            cnt++;
        }
        ans += pow(0.5, cnt);
    }
    ans = ans / n;
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}