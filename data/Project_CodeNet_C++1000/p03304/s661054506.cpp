#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    lint n, m, d;
    cin >> n >> m >> d;

    long double res = m-1;

    if (d == 0) {
        res /= n;
    }
    else {
        res *= 2 * (n-d);
        res /= n * n;
    }

    cout << fixed << setprecision(10) << res << endl;
    return 0;
}