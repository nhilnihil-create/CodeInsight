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
    int n = 1e5;
    vector<int> p(n + 1, 1);
    p[0] = 0, p[1] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 2; i * j <= n; j++) {
            p[i * j] = 0;
        }
    }
    vector<int> res(n + 1, 0);
    for (int i = 1; i <= n; i += 2) {
        if (p[i] == 1 && p[(i + 1) / 2] == 1) {
            res[i] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        res[i] += res[i - 1];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << res[r] - res[l - 1] << endl;
    }
}
