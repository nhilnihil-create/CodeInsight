#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;

int main() {
    int N, H, W;
    cin >> N >> H >> W;
    int ans = 0;
    rep(i, N) {
        int A, B;
        cin >> A >> B;
        if (A >= H && B >= W) ans += 1;
    }
    cout << ans << endl;
    return 0;
}