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

vec div(int n) {
    vec r(2);
    r[1] = ((n % 2) + 2) % 2;
    if (n < 0) {
        if (r[1] % 2) {
            r[0] = abs(n-1) / 2;
        }
        else {
            r[0] = abs(n) / 2;
        }
    }
    else {
        r[0] = n / 2;
        r[0] = -r[0];
    }
    return r;
}

int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0 << endl;
        exit(0);
    }

    string res = "";

    while (n != 1 && n != 0) {
        auto re = div(n);
        int q = re[0], r = re[1];
        n = q;
        res += to_string(r);
        if (q == 1) res += to_string(q);
    }

    reverse(all(res));
    cout << res << endl;
    return 0;
}