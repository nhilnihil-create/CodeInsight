#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);

    ll X, Y; cin >> X >> Y;

    int ans = 0;
    while (X <= Y) {
        ans++;
        X *= 2;
    }
    cout << ans << '\n';

    return 0;
}
