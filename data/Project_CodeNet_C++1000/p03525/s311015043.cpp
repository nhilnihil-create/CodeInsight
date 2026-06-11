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
    unordered_set<int> us1, us2;
    us1.insert(1);
    vector<int> c(13, 0);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        c[t]++;
        int max_val = 0;
        for (auto tt : us1) {
            int last = -1;
            int flag = 1;
            for (int i = 0; i < 24; i++) {
                if ((tt & (1 << i)) > 0) {
                    if (last != -1) {
                        if (i - last == 1) {
                            flag = 0;
                            break;
                        }
                    }
                    last = i;
                }
            }
            if (flag == 0) continue;
            if ((tt & (1 << t)) == 0) us2.insert(tt | (1 << t));
            if ((tt & (1 << (24 - t))) == 0 && t != 0) us2.insert(tt | (1 << (24 - t)));
        }
        swap(us1, us2);
    }

    for (int i = 1; i <= 12; i++) {
        if (c[i] >= 3 || c[0] > 0) {
            cout << 0 << endl;
            return 0;
        }
    }
    int res = 1;
    for (auto t : us1) {
        vector<int> v;
        for (int i = 0; i < 24; i++) {
            if ((t & (1 << i)) > 0) v.push_back(i);
        }
        if (n + 1 > v.size()) continue;
        int r = 24;
        if (v.size() > 0) r = min(r, -v.back() + 24 + v[0]);
        for (int i = 0; i < v.size() - 1; i++) {
            r = min(r, v[i + 1] - v[i]);
        }
        res = max(r, res);
    }
    cout << res << endl;
}
