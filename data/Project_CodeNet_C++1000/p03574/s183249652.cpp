#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};


int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }
    int bomb[51][51];
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            bomb[i][j] = -1;
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') {
                continue;
            } else {
                int cnt = 0;
                for (int dir = 0; dir < 8; dir++) {
                    int x = i + dx[dir];
                    int y = j + dy[dir];
                    if (x >= 0 && x < H && y >= 0 && y < W) {
                        if (S[x][y] == '#') {
                            cnt++;
                        }
                    }
                }
                bomb[i][j] = cnt;
            }
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (bomb[i][j] == -1) {
                cout << "#";
            } else {
                cout << bomb[i][j];
            }
        }
        cout << endl;
    }
}
