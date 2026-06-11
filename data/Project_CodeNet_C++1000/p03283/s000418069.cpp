#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <utility>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> tree(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        tree[r - l][l]++;
    }
    for (int j = 0; j < n - 1; j++) {
        tree[1][j] += tree[0][j] + tree[0][j + 1];
    }
    for (int i = 2; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            tree[i][j] += tree[i - 1][j] + tree[i - 1][j + 1] - tree[i - 2][j + 1];
        }
    }
    for (int i = 0; i < q; i++) {
        int p, q;
        cin >> p >> q;
        p--, q--;
        cout << tree[q - p][p] << endl;
    }
}
