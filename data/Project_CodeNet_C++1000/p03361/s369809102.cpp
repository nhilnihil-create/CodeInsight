#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> board(H);
    for (int i = 0; i < H; i++) {
        cin >> board.at(i);
    }

    bool can = true;
    const vector<int> dx = {1, 0, 0, -1};
    const vector<int> dy = {0, 1, -1, 0};
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            bool can2 = false;
            if (board.at(i).at(j) == '#'){
                for(int d = 0; d < 4; d++) {
                    const int ni = i + dx.at(d);
                    const int nj = j + dy.at(d);
                    if (ni >= 0 && ni < H
                        && nj >= 0 && nj < W
                        && board.at(ni).at(nj) == '#') {
                            can2 = true;
                        }
                } 
                can = can2;
            }
            if(!can) break;
        }
        if (!can) break;
    }

    if (can) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}