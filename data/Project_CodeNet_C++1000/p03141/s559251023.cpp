#include <iostream>
#include <algorithm>
#include <cmath>
#include <functional>
#include <string>
#include <vector>
#include <set>
using namespace std;

#define int long long
#define rep(n, i) for (int i = 0; i < n; i++)
#define rep2(m, n, i) for (int i = m; i < n; i++)
#define rep_r(n, i) for (int i = n - 1; i >= 0; i--)

const int INF = 1LL << 60;
const int MOD = 1e9 + 7;

typedef pair<int, int> P;
typedef pair<P, int> PP;

signed main() {
    int n;
    cin >> n;
    int c[n];
    int ans = 0;
    rep(n, i) {
        int a, b;
        cin >> a >> b;
        ans -= b;
        c[i] = a + b;
    }
    sort(c, c + n, greater<int>());
    rep(n, i) {
        if (i % 2) continue;
        ans += c[i];
    }
    cout << ans << endl;
    return 0;
}