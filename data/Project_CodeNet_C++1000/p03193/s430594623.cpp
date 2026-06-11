#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    lint n, h, w;
    cin >> n >> h >> w;

    int cnt = 0;
    while (n--) {
        llint a, b;
        cin >> a >> b;
        if (a >= h && b >= w)
            cnt++;
    }
    cout << cnt << endl;
}
