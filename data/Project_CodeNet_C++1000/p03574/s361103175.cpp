#include "bits/stdc++.h"

using namespace std;

void Main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> grids(H, vector<int>(W, 0));
    for (int i = 0; i < H; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < W; ++j) {
            grids[i][j] = (s[j] == '#') ? -1 : 0;
        }
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (grids[i][j] == 0) {
                int n = 0;
                if (i > 0 && j > 0 && grids[i - 1][j - 1] == -1) {
                    ++n;
                }
                if (i > 0 && grids[i - 1][j] == -1) {
                    ++n;
                }
                if (i > 0 && j < W - 1 && grids[i - 1][j + 1] == -1) {
                    ++n;
                }
                if (j > 0 && grids[i][j - 1] == -1) {
                    ++n;
                }
                if (j < W - 1 && grids[i][j + 1] == -1) {
                    ++n;
                }
                if (i < H - 1 && j > 0 && grids[i + 1][j - 1] == -1) {
                    ++n;
                }
                if (i < H - 1 && grids[i + 1][j] == -1) {
                    ++n;
                }
                if (i < H - 1 && j < W - 1 && grids[i + 1][j + 1] == -1) {
                    ++n;
                }
                grids[i][j] = n;
            }
        }
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (grids[i][j] == -1) {
                cout << "#";
            }
            else {
                cout << grids[i][j];
            }
        }
        cout << endl;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
