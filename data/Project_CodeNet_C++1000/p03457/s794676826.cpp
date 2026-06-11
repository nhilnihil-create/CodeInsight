#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 1e5 + 5;
int n, t, x, y, pt, px, py;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t >> x >> y;
        int dt = t - pt;
        int d = abs(x - px) + abs(y - py);
        if (d > dt) {
            cout << "No" << endl;
            exit(0);
        }
        if ((dt & 1) ^ (d & 1)) {
            cout << "No" << endl;
            exit(0);
        }

        pt = t;
        px = x;
        py = y;
    }
    cout << "Yes" << endl;
    return 0;
}
