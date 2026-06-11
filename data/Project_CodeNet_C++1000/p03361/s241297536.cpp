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


    int h, w;
    cin >> h >> w;
    vector<string> M(h);
    for (int i = 0; i < h; ++i) {
        cin >> M[i];
    }

    bool res = true;

    vector<int> X{-1, 1, 0, 0};
    vector<int> Y{0, 0, -1, 1};
    for (int i = 0; i < h && res; ++i) {
        for (int j = 0; j < w; ++j) {
            if (M[i][j] == '#') {
                int cnt = 0;
                for (int k = 0; k < 4; ++k) {
                    int x = i + X[k], y = j + Y[k];
                    if (x >= 0 && x < h && y >= 0 && y < w) {
                        if (M[x][y] == '#') {
                            ++cnt;
                        }
                    }
                }
                if (cnt == 0) {
                    res = false;
                    break;
                }
            }
        }
    }
    if (res) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}