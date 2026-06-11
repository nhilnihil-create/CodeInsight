#include <bits/stdc++.h>
using namespace std;

#define d(x) cerr << #x ":" << x << endl;
#define dd(x, y) cerr << "(" #x "," #y "):(" << x << "," << y << ")" << endl
#define rep(i, n) for (int i = (int)(0); i < (int)(n); i++)
#define repp(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define all(v) v.begin(), v.end()
#define dump(v)                  \
    cerr << #v ":[ ";            \
    for (auto macro_vi : v) {    \
        cerr << macro_vi << " "; \
    }                            \
    cerr << "]" << endl;
#define ddump(v)                           \
    cerr << #v ":" << endl;                \
    for (auto macro_row : v) {             \
        cerr << "[";                       \
        for (auto macro__vi : macro_row) { \
            cerr << macro__vi << " ";      \
        }                                  \
        cerr << "]" << endl;               \
    }
using lint       = long long;
const int INF    = 1e9;
const lint LINF  = 1e18;
const lint MOD   = 1e9 + 7;
const double EPS = 1e-10;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> G(H, vector<int>(W));
    rep(i, H) rep(j, W) {
        cin >> G[i][j];
        G[i][j] %= 2;
    }
    ddump(G);

    int cnt = 0;
    vector<vector<int>> O(0, vector<int>(4, 0));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W - 1; j++) {
            if (G[i][j] == 1) {
                cnt++;
                G[i][j + 1] += 1, G[i][j + 1] %= 2;
                O.push_back(vector<int>{i + 1, j + 1, i + 1, j + 2});
            } else {
                continue;
            }
        }
    }

    for (int i = 0; i < H - 1; i++) {
        if (G[i][W - 1] == 1) {
            cnt++;
            G[i + 1][W - 1] += 1, G[i + 1][W - 1] %= 2;
            O.push_back(vector<int>{i + 1, W, i + 2, W});
        } else {
            continue;
        }
    }

    cout << cnt << endl;
    for (int i = 0; i < O.size(); i++) {
        rep(j, 4) {
            cout << O[i][j];
            if (j < 3)
                cout << ' ';
            else
                cout << endl;
        }
    }

    return 0;
}