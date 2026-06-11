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

int f(const vector<pair<int, int>>& vp, int a) {
    int b = 0, e = vp.size() - 1;
    while (b < e) {
        int m = (b + e) / 2 + 1;
        if (vp[m].first >= a) {
            b = m;
        } else {
            e = m - 1;
        }
    }
    return b;
}

int main() {        
    long long int n, h;
    cin >> n >> h;
    vector<pair<int, int>> vp;
    vector<long long int> pre(n, 0);
    long long int s = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vp.emplace_back(b, a);
    }
    sort(vp.begin(), vp.end());
    reverse(vp.begin(), vp.end());
    for (int i = 0; i < n; i++) {
        s += vp[i].first;
        pre[i] = s;
    }
    int res = 0x3f3f3f3f;
    s = 0;
    for (int i = 0; i < n; i++) {
        s += vp[i].first;
        if (s >= h) {
            res = min(res, i + 1);
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        int index = f(vp, vp[i].second);
        long long int hh = h - pre[index];
        if (hh <= 0) {
            res = min(res, index + 1);
            continue;
        }
        int a = vp[i].second;
        res = min((long long int)res, (hh / a + (hh % a > 0 ? 1 : 0) + index + 1));

    }
    cout << res << endl;
}
