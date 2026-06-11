#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 0: 下、1: 右、2: 上、3: 左、4: 右下、5: 右上、6: 左上、7: 左下
vector<int> dx = {1, 0, -1, 0, 1, -1, -1, 1};
vector<int> dy = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
    // H x W の盤面を入力
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; ++i) cin >> S[i];

    // 各マス (i, j) を順に処理
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            // 空きマス以外はそのまま
            if (S[i][j] != '.') continue;

            // 周囲 8 マスを順に見ていく
            int counter = 0;
            for (int d = 0; d < 8; ++d) {
                int ni = i + dx[d], nj = j + dy[d];
                if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
                if (S[ni][nj] == '#') ++counter;
            }

            // マス (i, j) に個数を char 型に変換して記録
            S[i][j] = (char)('0' + counter);
        }
    }

    // 出力
    for (int i = 0; i < H; ++i) cout << S[i] << endl;
}