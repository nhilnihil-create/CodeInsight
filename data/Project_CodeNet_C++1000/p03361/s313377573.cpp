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

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void solve() {
    ll H, W;
    cin >> H >> W;
    vector<Vi> cell(H, Vi(W));
    for (ll i = 0; i < H; i++) {
        string s;
        cin >> s;
        for (ll j = 0; j < W; j++) {
            cell[i][j] = (s[j] == '#' ? 1 : 0);
        }
    }

    bool ok = true;
    constexpr int step[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (ll i = 0; i < H; i++) {
        for (ll j = 0; j < W; j++) {
            if (cell[i][j] == 0) continue;
            bool good = false;
            for (ll k = 0; k < 4; k++) {
                ll ni = i + step[k][0];
                ll nj = j + step[k][1];
                if (ni >= 0 && ni < H && nj >= 0 && nj < W) {
                    if (cell[ni][nj] == 1) {
                        good = true;
                    }
                }
            }

            if (!good) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            break;
        }
    }

    cout << (ok ? "Yes\n" : "No\n");
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

int main() {
#ifdef FASTIO
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
#endif
#ifdef FILEINPUT
    ifstream ifs("./in_out/input.txt");
    cin.rdbuf(ifs.rdbuf());
#endif
#ifdef FILEOUTPUT
    ofstream ofs("./in_out/output.txt");
    cout.rdbuf(ofs.rdbuf());
#endif
    solve();
    cout << flush;
    return 0;
}