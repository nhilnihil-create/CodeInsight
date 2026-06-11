#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int H, W;
    cin >> H >> W;
    string s[60];
    for (int i = 0; i < H; i++) cin >> s[i];

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (s[i][j] == '.') continue;
            bool ok = false;
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (x < 0 || x >= H || y < 0 || y >= W) continue;
                if (s[x][y] == '#') ok = true;
            }
            if (!ok) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}