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
    vec a(3);
    rep(i, 3) cin >> a[i];

    sort(all(a), greater<int>());

    cout << a[0] * 10 + a[1] + a[2] << endl;
    return 0;
}