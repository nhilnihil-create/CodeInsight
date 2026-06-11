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
    int n, m;
    cin >> n >> m;

    int res = 0;
    rep(i, m) res += 1900;
    rep(i, n-m) res += 100;

    int two = 1;
    rep(i, m) two *= 2;

    res *= two;

    cout << res << endl;
    return 0;
}