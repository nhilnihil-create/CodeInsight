#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;

int main() {
    ll X, Y;
    cin >> X >> Y;
    ll now = X;
    int ans = 0;
    while (now <= Y) {
        now *= 2;
        ans += 1;
    }
    cout << ans << endl;
    return 0;
}