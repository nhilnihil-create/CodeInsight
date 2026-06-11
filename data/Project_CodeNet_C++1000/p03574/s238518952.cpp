#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int main() {
    int H, W; cin >> H >> W;
    vector<vector<int>> S(H, vector<int>(W, 100));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c; cin >> c;
            if (c == '.') S[i][j] = 0;
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == 100) {
                for (int k = 0; k < 8; k++) {
                    if (0 <= i + dy[k] && i + dy[k] < H && 0 <= j + dx[k] && j + dx[k] < W) {
                        if (S[i + dy[k]][j + dx[k]] != 100) S[i + dy[k]][j + dx[k]]++;
                    }
                }
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == 100) cout << '#';
            else cout << S[i][j];
        }
        cout << endl;
    }

}
