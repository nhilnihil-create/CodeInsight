#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0, i##_len = (int)(n); i < i##_len; i++)

int main() {
    int n;
    long h, w;
    cin >> n >> h >> w;
    long ans = 0;
    rep(i, n) {
        long a, b;
        cin >> a >> b;
        if (a >= h && b >= w) ans++;
    }
    cout << ans << endl;
}
