#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double
#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) x.begin(), x.end()
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)

const static int MOD = 1000000000 + 7;
const static llong INF = 1LL << 60;
const static int dy[] = {0, 1, 0, -1};
const static int dx[] = {1, 0, -1, 0};

bool dp_x[5001][2 * 8000 + 1], dp_y[5001][2 * 8001 + 1]; //1-indexed

int main (int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;

    s += 'T'; // sentinell
    int cnt_F = 0, cnt_T = 0, cnt_X = 0, cnt_Y = 1;
    dp_y[0][8000] = true;
    rep(i, s.size()) {
        if (s[i] == 'F') {
            ++cnt_F;
        } else {
            ++cnt_T;
            if (cnt_T % 2) {
                if (cnt_T == 1) {
                    dp_x[cnt_X][8000 + cnt_F] = true;
                    ++cnt_X;
                } else {
                    for (int j = 0; j < 16001; ++j) {
                        if (! dp_x[cnt_X - 1][j]) continue;
                        if (j - cnt_F >= 0) dp_x[cnt_X][j - cnt_F] |= dp_x[cnt_X - 1][j];
                        if (j + cnt_F < 16001) dp_x[cnt_X][j + cnt_F] |= dp_x[cnt_X - 1][j];
                    }

                    ++cnt_X;
                }
            } else {
                for (int j = 0; j < 16001; ++j) {
                    if (! dp_y[cnt_Y - 1][j]) continue;
                    if (j - cnt_F >= 0) dp_y[cnt_Y][j - cnt_F] |= dp_y[cnt_Y - 1][j];
                    if (j + cnt_F < 16001) dp_y[cnt_Y][j + cnt_F] |= dp_y[cnt_Y - 1][j];
                }

                ++cnt_Y;
            }

            cnt_F = 0;
        }
    }

    if (dp_x[cnt_X - 1][8000 + x] && dp_y[cnt_Y - 1][8000 + y]) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}