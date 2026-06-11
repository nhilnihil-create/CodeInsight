#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    ll X, Y;
    cin >> X >> Y;

    int ans = 0;
    while (X <= Y) {
        X *= 2;
        ans++;
    }

    cout << ans << endl;

    return 0;
}