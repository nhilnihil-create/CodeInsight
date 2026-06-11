#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

constexpr ll infl = 10000000000000007LL;
constexpr int inf = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    int ans = 0;
    for (int k = 0; k < n; ++k) {
        vector<vector<char>> temp_grid(n, vector<char>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                temp_grid[i][j] = grid[(i + k) % n][j];
            }
        }

        bool symmetry = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (temp_grid[i][j] != temp_grid[j][i])
                    symmetry = false;
            }
        }

        if (symmetry)
            ++ans;
    }

    cout << ans * n << endl;
    return 0;
}