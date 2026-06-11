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
int h, w, d;

int main() {        
    cin >> h >> w >> d;
    vector<vector<int>> v1(h + 1, vector<int>(w + 1, 0));
    vector<pair<int, int>> v2(h * w + 1, make_pair(0, 0));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> v1[i][j];
            v2[v1[i][j]] = make_pair(i, j);
        }
    }
    int q;
    cin >> q;
    vector<long long int> v3(h * w + 1, 0);
    for (int i = 1; i <= h * w; i++) {
        if (i - d >= 1) {
            v3[i] = v3[i - d] + abs(v2[i].first - v2[i - d].first) + abs(v2[i].second - v2[i - d].second);
        } else {
            v3[i] = 0;
        }
    }
    for (int i = 0; i < q; i++) {
        long long int res = 0;
        int l, r;
        cin >> l >> r;
        cout << v3[r] - v3[l] << endl;
    }
}
