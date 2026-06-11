#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n + 1; i++)
#define ll long long int
#define INF 1000000007
// cin.eof() 入力個数の問題
int main() {
    int r, g, b, n;
    cin >> r >> g >> b >> n;
    int ans = 0;
    rep(i, n) {
        rep(j, n) {
            if ((n - i * r - j * g) % b == 0 && n - i * r - j * g >= 0)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
