#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w, n;
    cin >> h >> w >> n;

    set<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;

        st.insert({ x, y });
    }

    int i1 = h - 1;
    int j = 0;
    vector<int> b(h);
    for (int i = 0; i < h; i++) {
        if (i + 1 == h || st.count({ i + 1, j })) {
            b[i] = j;
            i1 = i;
            break;
        }
        if (j + 1 != w && !st.count({ i + 1, j + 1 })) {
            j++;
        }
        b[i] = j;
    }

    for (const auto& p : st) {
        int x = p.first;
        int y = p.second;
        if (x <= i1 && y < b[x]) {
            i1 = x - 1;
        }
    }

    cout << i1 + 1 << endl;

    return 0;
}