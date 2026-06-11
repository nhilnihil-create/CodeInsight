#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int l;
    cin >> l;
    l--;
    if (l == 1) {
        cout << 2 << " " << 2 << '\n';
        cout << 1 << " " << 2 << " " << 0 << '\n';
        cout << 1 << " " << 2 << " " << 1 << '\n';
        return 0;
    }
    if (l == 2) {
        cout << 2 << " " << 3 << '\n';
        cout << 1 << " " << 2 << " " << 0 << '\n';
        cout << 1 << " " << 2 << " " << 1 << '\n';
        cout << 1 << " " << 2 << " " << 2 << '\n';
        return 0;
    }
    int n = 3, k = 7;
    while (k <= l) {
        n++;
        k *= 2;
        k++;
    }
    vector<vector<int>> ans;
    k = 0;
    for (int i = 0; i < n - 1; i++) {
        ans.push_back({i + 1, i + 2, 1 << (n - i - 2)});
        ans.push_back({i + 1, i + 2, 0});
        k += 1 << (n - i - 2);
    }
    debug(k);
    while (k < l) {
        k++;
        int d = l - k;
        if (d == 0) {
            ans.push_back({1, n, l});
            break;
        }
        if (d == 1) {
            ans.push_back({1, n, l});
            ans.push_back({1, n, l - 1});
            break;
        }
        if (d == 2) {
            ans.push_back({1, n, l});
            ans.push_back({1, n, l - 1});
            ans.push_back({1, n, l - 2});
            break;
        }
        int m = n - 2, e = 7;
        while (e <= d) {
            m--;
            e *= 2;
            e++;
        }
        ans.push_back({1, m, k});
        k += e / 2;
    }
    cout << n << " " << ans.size() << '\n';
    for (auto v : ans) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << '\n';
    }
    return 0;
}