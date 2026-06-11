#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using li = long long int;
using uli = unsigned long long int;
using namespace std;

int find_mind(const vector<string> &cell, int i, int j, int height, int width) {
    int cnt = 0;
    for (auto x : {-1, 0, 1}) {
        for (auto y : {-1, 0, 1}) {
            int h = i + x;
            int w = j + y;
            if (0 <= h && h <= height - 1 && 0 <= w && w <= width - 1) {
                if (cell.at(h).at(w) == '#')
                    cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    fastIO;
    int h, w;
    cin >> h >> w;
    vector<string> cells(h);
    rep(i, h) cin >> cells.at(i);

    rep(i, h) {
        rep(j, w) {
            if (cells.at(i).at(j) != '#') {
                // find mines around cell
                int num = find_mind(cells, i, j, h, w);
                cells.at(i).at(j) = (char)(num + '0');
            }
        }
    }

    // output
    rep(i, h) {
        rep(j, w) cout << cells.at(i).at(j);
        cout << endl;
    }
}