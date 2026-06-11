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


    int H, W;
    cin >> H >> W;
    const int A = 10;
    vector<vector<int>> M(A, vector<int>(A, 0));

    for (int i = 0; i < A; ++i) {
        for (int j = 0; j < A; ++j) {
            cin >> M[i][j];
        }
    }

    for (int k = 0; k < A; ++k) {
        for (int i = 0; i < A; ++i) {
            for (int j = 0; j < A; ++j) {
                M[i][j] = min(M[i][j], M[i][k] + M[k][j]);
            }
        }
    }

    long long res = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            int x;
            cin >> x;
            if (x >= 0) {
                res += M[x][1];
            }
        }
    }

    cout << res << '\n';

    return 0;
}