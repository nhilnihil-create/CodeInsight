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

const int N = 10;
int e[N][N];
int h, w, t, ans;

int main() {
    cin >> h >> w;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> e[i][j];
        }
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k) {
                e[j][k] = min(e[j][k], e[j][i] + e[i][k]);
            }
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> t;
            if (t != -1) {
                ans += e[t][1];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
