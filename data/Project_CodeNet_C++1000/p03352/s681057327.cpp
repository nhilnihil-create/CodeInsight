#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int x;
    cin >> x;

    int ans = 0;
    for (int b = 1; b < 32; b++) {
        for (int p = 2; p < 10; p++) {
            int a = pow(b, p);
            if (a <= x) ans = max(ans, a);
        }
    }

    cout << ans << endl;
    return 0;
}
