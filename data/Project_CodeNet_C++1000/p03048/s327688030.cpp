#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int R, G, B, N;
    cin >> R >> G >> B >> N;

    ll ans = 0;
    rep(r, 3001) rep(g, 3001) {
        int bB = N - r * R - g * G;
        if (bB >= 0 && bB % B == 0) ans++;
    }

    cout << ans << endl;
    return 0;
}
