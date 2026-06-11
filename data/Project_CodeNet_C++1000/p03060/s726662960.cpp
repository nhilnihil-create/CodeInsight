#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
    int n, x=0, y=0;
    cin >> n;
    int maxprice = -10000000;
    vector<int>c(n), v(n);
    rep(i, n)cin >> c[i];
    rep(i, n)cin >> v[i];

    for (int i = 0; i < (1 << n); i++) {
        x = 0, y = 0;
        rep(j, n)if (i & (1 << j)) {
            x += v[j];
            y += c[j];
        }
        maxprice = max(maxprice, y - x);
    }

    cout << max(maxprice, 0) << endl;
    return 0;
}