#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<int, int>> e;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (i + j == (n + 1 - n % 2)) continue;
            e.push_back({i, j});
        }
    }
    cout << e.size() << "\n";
    for (auto p : e) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}