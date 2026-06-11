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
    int n, k;
    cin >> n >> k;

    lint res = 0;

    if (k % 2) {
        lint t = n;
        t /= k;
        res = t * t * t;
    }
    else {
        lint t = n;
        lint t1 = t / (k/2);
        lint t2 = t / k;
        res = t2 * t2 * t2;
        res += (t1 - t2) * (t1 - t2) * (t1 - t2);
    }

    cout << res << endl;
    return 0;
}