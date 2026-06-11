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
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;
    vec x(n), y(m);
    rep(i, n) cin >> x[i];
    rep(i, m) cin >> y[i];

    sort(all(x));
    sort(all(y));

    bool f = false;

    for (int z = X+1; z <= Y; z++) {
        bool f2 = true;

        if (!(X < z && z <= Y)) f2 = false;

        if (x[n-1] >= z) f2 = false;

        if (y[0] < z) f2 = false;

        if (f2) f = true;
    }

    if (f) cout << "No War" << endl;
    else cout << "War" << endl;
    return 0;
}