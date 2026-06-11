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

    int n = 3;
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> C[i][j];
        }
    }

    bool ok = true;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (C[i - 1][j] - C[i - 1][j - 1] != C[i][j] - C[i][j - 1]) {
                ok = false;
            }
        }
    }
    for (int j = 1; j < n; ++j) {   
        for (int i = 1; i < n; ++i) {
            if (C[i][j - 1] - C[i - 1][j - 1] != C[i][j] - C[i - 1][j]) {
                ok = false;
            }
        }
    }

    if (ok) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}