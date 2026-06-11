#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <deque>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <bitset>

using namespace std;
using ll = long long;

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    int prev = -1;
    vector<int> c;
    c.reserve(n);
    vector<int> total;
    total.reserve(n);
    int res = b.back() - b.front();
    for (int x : b) {
        if (x == prev) {
            continue;
        }
        prev = x;
        c.clear();
        total.clear();
        for (int v : a) {
            if (v < x) {
                sort(c.begin(), c.end());
                for (int i = 0; i <= (int)c.size() - k; ++i) {
                    total.push_back(c[i]);
                }
                c.clear();
            } else {
                c.push_back(v);
            }
        }
        sort(c.begin(), c.end());
        for (int i = 0; i <= (int)c.size() - k; ++i) {
            total.push_back(c[i]);
        }
        sort(total.begin(), total.end());
        if ((int)total.size() >= q) {
            res = min(res, total[q - 1] - x);
        }
    }
    cout << res << "\n";
    return 0;
}
