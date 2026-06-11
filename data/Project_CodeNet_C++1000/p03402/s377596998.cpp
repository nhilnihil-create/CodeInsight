#include <bits/stdc++.h>

using namespace std;

int main() {
    int w, b;
    cin >> w >> b;

    // グリッドの初期化
    char g[100][100];
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 100; ++j) {
            g[i][j] = '#';
            g[i + 50][j] = '.';
        }
    }

    // 白を塗る
    int white = 1;
    for (int i = 0; i < 50; i += 2) {
        for (int j = 0; j < 100; j += 2) {
            if (white == w) {
                break;
            } else {
                g[i][j] = '.';
                white++;
            }
        }
    }

    // 黒を塗る
    int black = 1;
    for (int i = 51; i < 100; i += 2) {
        for (int j = 0; j < 100; j += 2) {
            if (black == b) {
                break;
            } else {
                g[i][j] = '#';
                black++;
            }
        }
    }

    // 答えの表示
    cout << 100 << " " << 100 << endl;
    for (auto & i : g) {
        for (char j : i) {
            cout << j;
        }
        cout << endl;
    }
    return 0;
}