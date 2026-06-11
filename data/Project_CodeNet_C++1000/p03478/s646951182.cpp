#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b; cin >> n >> a >> b;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int tt = i, j = 0;
        while (tt) {
            j += tt % 10;
            tt /= 10;
        }
        if (a <= j && j <= b) ans += i;
    }
    cout << ans << endl;
}
