#include <bits/stdc++.h>

using namespace std;
using ll=long long ;

void solve() {
    int n; cin >> n;
    ll sum = 0; int mi = 2e9;
    bool eq = true;
    for (int _ = 0; _ < n; _++) {
        int x,y;
        cin >> x >> y;
        sum += x;
        if (x > y)
            mi = min(mi, y);
        eq &= x==y;
    }
    if (eq) cout << 0;
    else {
        cout << (sum-mi);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    cout << endl;
}
