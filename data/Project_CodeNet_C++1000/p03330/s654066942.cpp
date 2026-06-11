#include <bits/stdc++.h>
#define FASTIO
using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();

//==================================

int main() {
#ifdef FASTIO
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
#endif
#ifdef FILEINPUT
    ifstream ifs("./in_out/input.txt");
    cin.rdbuf(ifs.rdbuf());
#endif

    int N;
    cin >> N;

    int C;
    cin >> C;

    vector<Vi> cost(C, Vi(C));
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < C; j++) {
            cin >> cost[i][j];
        }
    }

    vector<Vi> cell(N, Vi(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> cell[i][j];
            --cell[i][j];
        }
    }

    vector<Vi> group(3, Vi(C));
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            if ((x + y) % 3 == 0) {
                ++group[0][cell[x][y]];
            }
            else if ((x + y) % 3 == 1) {
                ++group[1][cell[x][y]];
            }
            else {
                ++group[2][cell[x][y]];
            }
        }
    }

    ll ans = L_INF;

    for (int i = 0; i < C; i++) {
        for (int j = 0; j < C; j++) {
            for (int k = 0; k < C; k++) {
                if (i == j || j == k || k == i) {
                    continue;
                }
                ll score = 0;
                for (int c = 0; c < C; c++) {
                    score += group[0][c] * cost[c][i];
                }
                for (int c = 0; c < C; c++) {
                    score += group[1][c] * cost[c][j];
                }
                for (int c = 0; c < C; c++) {
                    score += group[2][c] * cost[c][k];
                }
                ans = min(ans, score);
            }
        }
    }

    cout << ans << "\n";

    return 0;
}