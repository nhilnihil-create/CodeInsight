#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define dump(x) cout << x << endl
typedef int64_t Int;

using namespace std;
using Graph = vector<vector<Int>>;

const double pi = M_PI;
const Int MOD = 1000000007;

int main() {
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;
    vector<int> x(n), y(m);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> y[i];
    }

    int xm = *max_element(x.begin(), x.end());
    int ym = *min_element(y.begin(), y.end());

    if (Y - X >= 1 && ym - xm >= 1 && xm < Y && X < ym) {
        cout << "No War" << endl;
    } else {
        cout << "War" << endl;
    }

    return 0;
}
