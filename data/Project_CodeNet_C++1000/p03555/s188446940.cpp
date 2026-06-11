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
    int h = 2;
    int w = 3;
    vector<string> c(h);
    rep(i, h) cin >> c[i];

    bool f = true;

    rep(i, h) rep(j, w) {
        if (c[i][j] != c[h-1-i][w-1-j]) f = false;
    }

    if (f) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}