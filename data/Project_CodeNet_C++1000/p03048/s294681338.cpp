#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    int ans = 0;
    rep(r, N + 1) rep(g, N + 1) {
        int b = (N - R * r - G * g) / B;
        if (R * r + G * g + B * b == N && b >= 0) ++ans;
    }
    cout << ans << endl;
    return 0;
}
