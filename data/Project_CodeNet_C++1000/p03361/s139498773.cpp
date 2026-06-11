#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <limits>
#include <climits>
#include <utility>
#include <algorithm>
#include <numeric>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int dx[4] = { 0,  0, 1, -1 };
int dy[4] = { 1, -1, 0,  0 };

int main()
{
    int H, W;
    cin >> H >> W;

    vector<string> s(H);
    for (int i = 0; i < H; ++i) {
        cin >> s[i];
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (s[i][j] == '#') {
                bool ok = false;

                for (int k = 0; k < 4; ++k) {
                    int x = j + dx[k];
                    int y = i + dy[k];

                    if (x < 0 || W <= x || y < 0 || H <= y) {
                        continue;
                    }

                    if (s[y][x] == '#') {
                        ok = true;
                    }
                }

                if (!ok) {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}
