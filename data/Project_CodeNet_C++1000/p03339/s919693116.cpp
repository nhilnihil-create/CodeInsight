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
    int n;
    cin >> n;
    string s;
    cin >> s;

    vec l(n), r(n);

    for (int i = 1; i < n; i++) {
        l[i] = l[i-1];
        if (s[i-1] == 'W') l[i]++;
    }

    for (int i = n-2; i >= 0; i--) {
        r[i] = r[i+1];
        if (s[i+1] == 'E') r[i]++;
    }

    int res = INF;

    rep(i, n) {
        res = min(res, l[i] + r[i]);
    }

    cout << res << endl;
    return 0;
}