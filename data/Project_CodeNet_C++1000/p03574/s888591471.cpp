#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;


int main() {
    int h, w;
    cin >> h >> w;
    vector<string> vs;
    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;
        vs.push_back(s);
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (vs[i][j] == '.') {
                vs[i][j] = '0';
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (vs[i][j] == '#') {
                for (int a = -1; a <= 1; a++) {
                    for (int b = -1; b <= 1; b++) {
                        int x = i + a, y = j + b;
                        if (x < 0 || y < 0 || x >= h || y >= w || vs[x][y] == '#') continue;
                        vs[x][y]++;
                    }
                }
            }
        }
    }
    for (auto s : vs) {
        cout << s << endl;
    }
}


