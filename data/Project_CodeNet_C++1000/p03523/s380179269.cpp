#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    string t;
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (s[i] != 'A') {
            t.push_back(s[i]);
        }
    }
    string need = "KIHBR";
    ok &= (t == need);
    if (!ok) {
        cout << "NO\n";
        return 0;
    }
    vector<int> where(need.size());
    for (int i = 0, j = 0; i < n && j < need.size(); i++) {
        if (s[i] == need[j]) {
            where[j] = i;
            j++;
        }
    }
    ok &= (where[0] <= 1);
    ok &= (where[1] == where[0] + 1);
    ok &= (where[2] == where[1] + 1);
    ok &= (where[3] - where[2] <= 2);
    ok &= (where[4] - where[3] <= 2);
    ok &= (n - 1 - where[4] <= 1);
    cout << (ok ? "YES\n" : "NO\n");
}