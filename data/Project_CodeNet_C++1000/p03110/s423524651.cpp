#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define dump(x) cout << x << endl
typedef int64_t Int;

using namespace std;
using Graph = vector<vector<Int>>;

const double pi = M_PI;
const Int MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    long double ans = 0;
    pair<long double, string> xu;
    for (int i = 0; i < n; i++) {
        cin >> xu.first >> xu.second;
        if (xu.second == "BTC") {
            ans += xu.first * 380000.0;
        } else {
            ans += xu.first;
        }
    }

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}
