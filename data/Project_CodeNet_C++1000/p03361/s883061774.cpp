#include "bits/stdc++.h"

using namespace std;

bool judge(const vector<vector<bool>>& picture) {
    int H = picture.size();
    int W = picture.front().size();
}

void Main() {
    int H, W;
    cin >> H >> W;
    vector<vector<bool>> picture(H, vector<bool>(W, false));
    for (int i = 0; i < H; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < W; ++j) {
            picture[i][j] = (s[j] == '#');
        }
    }

    bool ans = true;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (picture[i][j]) {
                bool ip1 = (i < H - 1) && picture[i + 1][j];
                bool im1 = (i > 0) && picture[i - 1][j];
                bool jp1 = (j < W - 1) && picture[i][j + 1];
                bool jm1 = (j > 0) && picture[i][j - 1];
                if (ip1 || im1 || jp1 || jm1) {
                    continue;
                }
                else {
                    ans = false;
                    break;
                }
            }
        }
        if (!ans) {
            break;
        }
    }
    cout << (ans ? "Yes" : "No") << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
