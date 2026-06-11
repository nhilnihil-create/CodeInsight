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
    vector<int> v(1, 1);
    for (int i = 6; i <= n; i *= 6) {
        v.push_back(i);
    }
    for (int i = 9; i <= n; i *= 9) {
        v.push_back(i);
    }
    vector<int> res(n + 1, 0x3f3f3f3f);
    res[0] = 0;
    for (int i = 0; i <= n; i++) {
        if (res[i] == 0x3f3f3f3f) continue;
        for (int j = 0; j < v.size(); j++) {
            if (i + v[j] <= n) {
                res[i + v[j]] = min(res[i + v[j]], res[i] + 1);
            }
        }
    }
    cout << res[n] << endl;
}
