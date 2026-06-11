#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int h, w;
    cin >> h >> w;
    vector<int> dx = {1, 1, 0, -1, -1, -1, 0, 1};
    vector<int> dy = {0, 1, 1, 1, 0, -1, -1, -1};
    vector<string> board;
    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;
        board.push_back(s);
    }
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (board.at(y).at(x) == '#') continue;
            int n = 0;
            for (int di = 0; di < 8; di++) {
                if (x + dx.at(di) < 0 || w <= x + dx.at(di)) continue;
                if (y + dy.at(di) < 0 || h <= y + dy.at(di)) continue;
                if (board.at(y + dy.at(di)).at(x + dx.at(di)) == '#') {
                    n++;
                }
            }
            board.at(y).at(x) = '0' + n;
        }
    }
    for (auto &&i : board) {
        cout << i << endl;
    }
    return 0;
}