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
    lint x, y;
    cin >> x >> y;

    lint res = 0;
    lint cur = x;
    while (cur <= y) {
        cur *= 2;
        res++;
    }

    cout << res << endl;
    return 0;
}