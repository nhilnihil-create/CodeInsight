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
    vector<vector<int>> v(2, vector<int>(n, 0));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            int t = 0;
            cin >> t;
            v[i][j] = t;
            if (j > 0) {
                v[i][j] = max(v[i][j], v[i][j - 1] + t);
            }
            if (i > 0) {
                v[i][j] = max(v[i][j], v[i - 1][j] + t);
            }
        }
    }
    cout << v[1][n-1] << endl;
}


