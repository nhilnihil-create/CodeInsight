#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    Int n; cin >> n;
    Int minv = 0;

    rep(i, 5) {
        Int tmp; cin >> tmp;
        if (i == 0) minv = tmp;
        else {
            minv = min(minv, tmp);
        }
    }
    if (n <= minv) {
        cout << 5 << endl;
        return 0;
    }
    Int ans = (n + minv -1) / minv + 4;
    cout << ans << endl;
}