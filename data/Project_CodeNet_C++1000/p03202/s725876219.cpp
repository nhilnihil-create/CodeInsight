#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <random>
#include <complex>
#include <random>
 
using namespace std;

namespace String {
    int lim;
    vector<pair<int, int>> v;

    void trim(int x) {
        while (!v.empty() && prev(v.end())->first >= x) {
            v.pop_back();
        }
    }

    bool add(int to) {
        vector<pair<int, int>> poped;
        for (int i = to; i >= 0; i--) {
            if (v.empty() || v.back().first < i) {
                v.push_back({i, 1});
                break;
            }
            v.back().second++;
            if (v.back().second == lim) {
                if (i == 0) return false;
                poped.push_back({v.back().first, 0});
                v.pop_back();
            } else {
                break;
            }
        } 
        reverse(poped.begin(), poped.end());
        for (auto t : poped) {
            v.push_back(t);
        }
        return true;
    }

    void init(int lim_) {
        lim = lim_;
        v.clear();
    }
};

int n;
vector<int> a;

bool can(int x) {
    String::init(x);
    int clen = 0;
    for (int i = 0; i < n; i++) {
        if (clen < a[i]) {
            //
        } else {
            String::trim(a[i]);
            if (!String::add(a[i] - 1)) {
                return false;
            }
        }
        clen = a[i];
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    a.resize(n);
    for (auto &t : a) {
        cin >> t;
    }
    {
        int ans1 = 1;
        for (int i = 0; i + 1 < n; i++) {
            if (a[i] >= a[i + 1]) {
                ans1 = 0;
            }
        }
        if (ans1) {
            cout << 1 << endl;
            exit(0);
        }
    }
    int l = 1;
    int r = n;
    while (r - l > 1) {
        int m = (r + l) >> 1;
        if (can(m)) {
            r = m;
        } else {
            l = m;
        }
    }       
    cout << r << endl;
}
