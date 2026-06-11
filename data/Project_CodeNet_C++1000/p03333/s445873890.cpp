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
#include <complex>
#include <random>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        a.push_back({l, r});
    }
    int res = 0;
    auto tryy = [&](vector<pair<int, int>> ord) {
        ord.push_back({0, 0});
        int cpos = 0;
        int ans = 0;
        for (auto t : ord) {
            int l, r;
            tie(l, r) = t;
            if (l <= cpos && cpos <= r) {
                //
            } else if (cpos <= l) {
                ans += abs(cpos - l);
                cpos = l;
            } else {
                ans += abs(cpos - r);
                cpos = r;
            }
        }
        res = max(res, ans);
    };
    vector<pair<int, int>> ord;
    {
        vector<int> ind1(n);
        iota(ind1.begin(), ind1.end(), 0);
        vector<int> ind2 = ind1;
        sort(ind1.rbegin(), ind1.rend(), [&](int i, int j) {
            return a[i].first < a[j].first;
        });
        sort(ind2.begin(), ind2.end(), [&](int i, int j) {
            return a[i].second < a[j].second;
        });
        set<int> hv;
        for (int i = 0; i < 2 * n; i++) {
            int v = -1;
            if ((i & 1)) {
                v = ind2[i / 2];
            } else {
                v = ind1[i / 2];
            }
            if (!hv.count(v)) {
                hv.insert(v);
                ord.push_back(a[v]);
            }
        }
        tryy(ord);
        hv.clear();
        ord.clear();
        for (int i = 0; i < 2 * n; i++) {
            int v = -1;
            if (!(i & 1)) {
                v = ind2[i / 2];
            } else {
                v = ind1[i / 2];
            }
            if (!hv.count(v)) {
                hv.insert(v);
                ord.push_back(a[v]);
            }
        }
        tryy(ord);
    }
    
    cout << res << endl;
}   
