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
    int n, c;
    cin >> n >> c;
    vector<vector<int>> d(c + 1, vector<int>(c + 1, 0));
    for (int i = 1; i <= c; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> d[i][j];
        }
    }
    vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> vc(3, vector<int> (c + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
            vc[(i + j) % 3][v[i][j]]++;
        }
    }

    int res = -1;
    for (int i = 1; i <= c; i++) {
        for (int j = 1; j <= c; j++) {
            if (i == j) continue;
            for (int k = 1; k <= c; k++) {
                if (i == k || j == k) continue;
                int r = 0;
                for (int a = 1; a <= c; a++) {
                    if (a != i) {
                        r += vc[0][a] * d[a][i];
                    }
                    if (a != j) {
                        r += vc[1][a] * d[a][j];
                    }
                    if (a != k) {
                        r += vc[2][a] * d[a][k];
                    }
                }
                if (res == -1 || r < res) {
                    res = r;
                }
            }
        }
    }
    cout << res << endl;
}
