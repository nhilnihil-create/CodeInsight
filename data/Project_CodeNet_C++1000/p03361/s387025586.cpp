#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> S(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> S.at(i).at(j);
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S.at(i).at(j) == '#') {
                if (S.at(max(i - 1, 0)).at(j) == '.'
                && S.at(min(i + 1, H - 1)).at(j) == '.'
                && S.at(i).at(max(j - 1, 0)) == '.'
                && S.at(i).at(min(j + 1, W - 1)) == '.') {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
}
