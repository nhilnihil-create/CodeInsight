#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(12);


    int h, w;
    cin >> h >> w;
    vector<string> M(h);
    for (int i = 0; i < h; ++i) {
        cin >> M[i];
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (M[i][j] == '.') {
                int cnt = 0;
                for (int a = -1; a < 2; ++a) {
                    for (int b = -1; b < 2; ++b) {
                        int x = i + a, y = j + b;
                        if (x >= 0 && x < h && y >= 0 && y < w && !(x == i && y == j)) {
                            if (M[x][y] == '#') {
                                ++cnt;
                            }
                        }
                    }
                }
                M[i][j] = (char)('0' + cnt);
            }
        }
    }

    for (int i = 0; i < h; ++i) {
        cout << M[i] << '\n';
    }

    return 0;
}