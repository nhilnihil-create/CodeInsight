#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

int main() {
    fastIO;
    int n, t;
    cin >> n >> t;

    vector<int> C(n);
    vector<int> T(n);

    rep(i, n) {
        cin >> C.at(i);
        cin >> T.at(i);
    }

    // output
    int min_cost = 1001;
    rep(i, n) {
        if (t >= T.at(i)) {
            min_cost = min(min_cost, C.at(i));
        }
    }

    if (min_cost != 1001)
        cout << min_cost << endl;
    else
        cout << "TLE" << endl;
}
