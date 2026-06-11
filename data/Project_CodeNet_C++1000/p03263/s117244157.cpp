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

using Tup = tuple<ll, ll, ll, ll>;

void solve() {
    ll H, W;
    cin >> H >> W;
    vector<Vi> cell(H, Vi(W));
    for (ll i = 0; i < H; i++) {
        for (ll j = 0; j < W; j++) {
            cin >> cell[i][j];
        }
    }
    vector<Tup> ans;
    for (ll i = 0; i < H; i++) {
        if (!(i & 1)) {
            for (ll j = 0; j < W - 1; j++) {
                if (cell[i][j] & 1) {
                    --cell[i][j];
                    ++cell[i][j + 1];
                    ans.emplace_back(i, j, i, j + 1);
                }
            }
            if (i < H - 1 && cell[i][W - 1] & 1) {
                --cell[i][W - 1];
                ++cell[i + 1][W - 1];
                ans.emplace_back(i, W - 1, i + 1, W - 1);
            }
        }
        else {
            for (ll j = W - 1; j >= 1; j--) {
                if (cell[i][j] & 1) {
                    --cell[i][j];
                    ++cell[i][j - 1];
                    ans.emplace_back(i, j, i, j - 1);
                }
            }
            if (i < H - 1 && cell[i][0] & 1) {
                --cell[i][0];
                ++cell[i + 1][0];
                ans.emplace_back(i, 0, i + 1, 0);
            }
        }
    }

    cout << ans.size() << "\n";
    for (const auto& v : ans) {
        ll a, b, c, d;
        tie(a, b, c, d) = v;
        cout << a + 1 << " " << b + 1 << " " << c + 1 << " " << d + 1 << "\n";
    }
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