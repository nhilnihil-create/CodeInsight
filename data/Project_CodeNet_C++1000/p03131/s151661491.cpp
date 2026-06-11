#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int k, a, b; cin >> k >> a >> b;
    if (b-a <= 2) {
        cout << k+1 << endl;
        return 0;
    }
    Int ans = 1;
    for (int i = 0; i < k; i++) {
        if (ans >= (Int)a && i+1<k) {
            i += 1;
            ans += (b-a);
            continue;
        }
        ans++;
    }
    cout << ans << endl;
}