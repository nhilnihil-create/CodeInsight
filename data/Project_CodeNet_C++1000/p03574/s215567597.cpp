#include <iostream>
#include <vector>
using namespace  std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> S(H, vector<char>(W));
    vector<vector<int>> T(H, vector<int>(W, 0));

    for (int i=0; i<H; ++i) {
        for (int j=0; j<W; ++j) {
            cin >> S[i][j];
        }
    }

    for (int i=0; i<H; ++i) {
        for (int j=0; j<W; ++j) {
            if (S[i][j] == '#') continue;

            for (int dy=-1; dy<=1; ++dy) {
                for (int dx=-1; dx<=1; ++dx) {
                    if (dx == 0 && dy == 0) continue;
                    int ny = i + dy;
                    int nx = j + dx;
                    if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
                    if (S[ny][nx] == '#') {
                        ++T[i][j];
                    }
                }
            }
        }
    }
    for (int i=0; i<H; ++i) {
        for (int j=0; j<W; ++j) {
            if (S[i][j] == '.')
                cout << T[i][j];
            else
                cout << S[i][j];
        }
        cout << endl;
    }

}
