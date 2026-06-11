#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;

int main() {
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    int ans = 0;
    rep(i, N + 1) rep(j, N + 1) {
        int b = -(i*R + j*G - N)/B;
        if (i*R + j*G + b*B == N && b >= 0) ans += 1;
    }
    cout << ans << endl;
    return 0;
}