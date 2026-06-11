#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll ans;
ll mi = 1e18;

int main() {
    cin >> n;
    bool f = 1;
    for (int i = 0; i < n; i++) {
        ll a,b;
        cin >> a >> b;
        ans += a;
        if (a != b) f = 0;
        if (a > b) mi = min(mi, b);
    }
    if (f) {
        cout << 0 << endl;
        return 0;
    }
    cout << ans - mi << endl;
    return 0;
}
