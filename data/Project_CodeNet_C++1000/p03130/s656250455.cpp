#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    int g[4][4] = {};

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (i != j) {
                g[i][j] = INF;
            }
        }
    }

    for (int i = 0; i < 3; ++i) {
        int a, b; cin >> a >> b;

        --a; --b;

        g[a][b] = 1;
        g[b][a] = 1;
    }

    for (int k = 0; k < 4; ++k) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (g[i][j] == 3) {
                puts("YES");
                return 0;
            }
        }
    }

    puts("NO");
}