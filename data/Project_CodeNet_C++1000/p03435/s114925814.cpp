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

static const int N = 3;
int grid[N][N];

int main() {
    bool ok = true;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> grid[i][j];
        }
    }
    for (int i = 1; i < 3; ++i) {
        for (int j = 1; j < 3; ++j) {
            if (grid[i][j] - grid[i][j - 1] != grid[0][j] - grid[0][j - 1]) {
                ok = false;
            }
            if (grid[i][j] - grid[i - 1][j] != grid[i][0] - grid[i - 1][0]) {
                ok = false;
            }
        }
    }
    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
