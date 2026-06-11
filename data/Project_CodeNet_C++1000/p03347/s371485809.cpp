#include <bits/stdc++.h>
//#include "atcoder/all"
typedef long long int ll;
using namespace std;
// using namespace atcoder;
int main() {
    int n;
    cin >> n;
    ll ret = 0;
    ll now = -1;
    bool ok = true;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        if (a >= now + 2) {
            ok = false;
        }
        else if (a == now + 1) {
            now = a;
            if (i == n - 1) ret += a;
        }
        else {
            ret += now;
            now = a;
            if (i == n - 1) ret += a;
        }
    }
    if (!ok) cout << -1 << endl;
    else cout << ret << endl;
    return 0;
}