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

int f(int num, const vector<int>& v) {
    int n = v.size();
    if (num <= v[0]) return -1;
    int b = 0, e = n - 1;
    while (b < e) {
        int m = (b + e) / 2 + 1;
        if (v[m] < num) {
            b = m;
        } else {
            e = m - 1;
        }
    }
    return b;
}

int main() {
    int n;
    cin >> n;
    vector<int> va(n, 0), vb(n, 0), vc(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> va[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> vb[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> vc[i];
    }
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    sort(vc.begin(), vc.end());
    vector<long long int> res1(n, 1), res2(n, 0), res3(n, 0);
    for (int i = 0; i < n; i++) {
        res1[i] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        int index = f(vb[i], va);
        if (index >= 0) {
            res2[i] = res1[index];
            if (i > 0) {
                res2[i] += res2[i - 1];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int index = f(vc[i], vb);
        if (index >= 0) {
            res3[i] = res2[index];
            if (i > 0) {
                res3[i] += res3[i - 1];
            }
        }
    }
    cout << res3.back() << endl;
}


