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
    vector<vector<int>> v1(c + 1, vector<int>(0)), v2(c + 1, vector<int>(0));
    for (int i = 0; i < n; i++) {
        int s, t, cc;
        cin >> s >> t >> cc;
        v1[cc].push_back(s);
        v1[cc].push_back(t);
    }
    vector<int> begin(100001, 0), end(100001, 0);
    for (int i = 1; i <= c; i++) {
        sort(v1[i].begin(), v1[i].end());
        for (auto num : v1[i]) {
            if (v2[i].size() > 0 && v2[i].back() == num) {
                v2[i].pop_back();
            } else {
                v2[i].push_back(num);
            }
        }
        for (int j = 0; j < v2[i].size(); j += 2) {
            begin[v2[i][j]]++;
            end[v2[i][j + 1]]++;
        }
    }

    int res = 0;
    int r = 0;
    for (int i = 1; i <= 100000; i++) {
        r += begin[i];
        res = max(r, res);
        r -= end[i];
    }
    cout << res << endl;
}
