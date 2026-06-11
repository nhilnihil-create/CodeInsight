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
    int white = 0;
    for (auto r : vs) {
        for (auto c : r) {
            if (c == '.') white++;
        }
    }
    vector<pair<int, int>> vp1, vp2;
    vp1.push_back(make_pair(0, 0));
    int d = 1;
    vs[0][0] = '#';
    vector<vector<int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while (vp1.size() > 0) {
        vp2.clear();
        for (auto node : vp1) {
            if (node.first == h - 1 && node.second == w - 1) {
                cout << white - d << endl;
                return 0;
            }
            for (auto d : dir) {
                int x = d[0] + node.first, y = d[1] + node.second;
                if (x < 0 || y < 0 || x >= h || y >= w) continue;
                if (vs[x][y] == '.') {
                    vs[x][y] = '#';
                    vp2.push_back(make_pair(x, y));
                }
            }
        }
        d++;
        vp1 = vp2;
    }
    cout << -1 << endl;
}


