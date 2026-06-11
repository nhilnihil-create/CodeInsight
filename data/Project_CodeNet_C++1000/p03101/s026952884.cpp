#pragma GCC target ("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    int H, W, h, w;
    cin >> H >> W >> h >> w;

    int res = H * W;
    res -= H * w;
    res -= W * h;
    res += w * h;
    cout << res << endl;
    return 0;
}