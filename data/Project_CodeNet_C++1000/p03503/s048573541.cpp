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
    int n;
    cin >> n;
    vector<vector<int>> f(n, vector<int>(10, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> f[i][j];
        }
    }
    vector<vector<int>> p(n, vector<int>(11, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 11; j++) {
            cin >> p[i][j];
        }
    }
    int res = -0x3f3f3f3f;
    for (int i = 1; i < 1024; i++) {
        int r = 0;
        for (int j = 0; j < n; j++) {
            int c = 0;
            for (int k = 0; k < 10; k++) {
                c += ((i >> k) & 1) * f[j][k];
            }
            r += p[j][c];
        }
        res = max(res, r);
    }
    cout << res << endl;
}


