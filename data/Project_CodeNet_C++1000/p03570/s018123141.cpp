#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = (int)s.size();
    int a = 0;

    map<int, int> mp;
    mp[0] = 0;

    for (int i = 0; i < n; i++) {
        a ^= 1 << (s[i] - 'a');
        int m = n;
        for (int k = 1 << ('z' - 'a');; k >>= 1) {
            auto it = mp.find(a ^ k);
            if (it != mp.end()) {
                int t = it->second + 1;
                if (t < m) m = t;
            }
            if (k == 0) break;
        }

        if (i == n - 1) {
            cout << m << endl;
            quick_exit(0);
        }
        auto it = mp.find(a);
        if (it == mp.end()) mp.insert(make_pair(a, m)); else it->second = min(it->second, m);
    }

    return 0;
}