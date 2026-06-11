#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

signed main() {
    double n, m;
    int d;
    cin >> n >> m >> d;
    double per;
    if (d == 0) {
        per = 1 / n * (m - 1);
    } else {
        per = 2 * (n - d) / n / n * (m - 1);
    }
    cout << fixed << setprecision(10) << per << "\n";
}
