#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
ll const INF = 1LL << 60;
ll const MAX_N = 510000;
ll const MOD = 1000000007;

int main() {
    vector<vector<ll>> c(3, vector<ll>(3));
    rep(i, 3) rep(j, 3) cin >> c[i][j];

    for (int a1 = 0; a1 <= 100; a1++) {
        ll b1 = c[0][0] - a1;
        ll b2 = c[0][1] - a1;
        ll b3 = c[0][2] - a1;
        ll a2 = c[1][0] - b1;
        ll a3 = c[2][0] - b1;

        if (a2 + b2 == c[1][1] && a2 + b3 == c[1][2] && a3 + b2 == c[2][1] &&
            a3 + b3 == c[2][2]) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
