#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct pos {
    int x, y;
};

int h, w;
const vector<pos> moves{{1,  0},
                        {-1, 0},
                        {0,  1},
                        {0,  -1}};

bool inRange(pos p) {
    return 0 <= p.x && p.x < h && 0 <= p.y && p.y < w;
}

int main() {
    cin >> h >> w;
    vector<string> v(h);
    for (int i = 0; i < h; i++)cin >> v[i];

    bool ret = true;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (v[i][j] == '#') {
                pos here = {i, j};
                bool found = false;
                for (auto move:moves) {
                    pos next = {here.x + move.x, here.y + move.y};
                    if (inRange(next) && v[next.x][next.y] == '#')found = true;
                }
                if (!found) ret = false;
            }
        }
    }

    cout << (ret ? "Yes" : "No") << endl;
    return 0;
}