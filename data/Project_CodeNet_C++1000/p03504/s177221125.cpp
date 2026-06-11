#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n, c;
    cin >> n >> c;
    vector<vector<int>> xs(c, vector<int>((int)1e5 + 1));
    for (int i = 0; i < n; ++i) {
        int s, t, c;
        cin >> s >> t >> c;
        --c;
        ++xs[c][s];
        --xs[c][t];
    }
    for (int ci = 0; ci < c; ++ci) {
        for (int xi = 1; xi < xs[ci].size(); ++xi) {
            xs[ci][xi] += xs[ci][xi - 1];
        }
    }
    for (int ci = 0; ci < c; ++ci) {
        for (int xi = 1; xi < xs[ci].size(); ++xi) {
            if (xs[ci][xi - 1] == 0 && xs[ci][xi] == 1)
                xs[ci][xi - 1] = 1;
        }
    }
    int ans = 0;
    for (int xi = 0; xi < xs[0].size(); ++xi) {
        int s = 0;
        for (int ci = 0; ci < c; ++ci) {
            s += xs[ci][xi];
        }
        ans = max(ans, s);
    }
    cout << ans << endl;
    return 0;
}
