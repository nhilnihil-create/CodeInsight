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

const int N = 505;
int n, c, ans;
int a[N][N], d[33][33];
int cost[3][31];

int main() {
    ans = 0x3f3f3f3f;
    cin >> n >> c;
    for (int i = 1; i <= c; ++i) {
        for (int j = 1; j <= c; ++j) {
            cin >> d[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    for (int k = 1; k <= c; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cost[(i + j) % 3][k] += d[a[i][j]][k];
            }
        }
    }
    for (int i = 1; i <= c; ++i) {
        for (int j = 1; j <= c; ++j) {
            for (int k = 1; k <= c; ++k) {
                if (i == j || j == k || i == k) continue;
                ans = min(ans, cost[0][i] + cost[1][j] + cost[2][k]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
