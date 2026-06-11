#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    int q; cin >> q;
    auto solve = [&](int k) {
        long long dmc = 0, dm = 0;
        queue<int> ds;
        for (int i = 0, m = 0; i < n; i++) {
            if (s[i] == 'D') ds.emplace(m);
            if (s[i] == 'M') dm += ds.size(), m++;
            if (s[i] == 'C') dmc += dm;
            if (i >= k - 1 && s[i - k + 1] == 'D') {
                dm -= m - ds.front(), ds.pop();
            }
        }
        return dmc;
    };
    while (q--) {
        int k; cin >> k;
        cout << solve(k) << endl;
    }
    return 0;
}
