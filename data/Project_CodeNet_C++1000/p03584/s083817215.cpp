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

void f(const vector<pair<int, int>>& vp, int k, long long int& res) {
    long long int r = 0;
    for (int i = 0; i < vp.size(); i++) {
        if ((vp[i].first | k) == k) {
            r += vp[i].second;
        }
    }
    res = max(res, r);
}

int main() {        
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vp.emplace_back(a, b);
    }
    long long int res = 0;
    f(vp, k, res);
    for (int i = 29; i >= 0; i--) {
        if ((k & (1 << i)) > 0) {
            int kk = k - (1 << i);
            kk |= (1 << i) - 1;

            f(vp, kk, res);
        }
    }
    cout << res << endl;
}
