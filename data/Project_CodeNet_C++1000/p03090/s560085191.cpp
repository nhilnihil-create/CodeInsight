#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    cin >> n;
    vector<pair<int, int>> V;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (j ^ (n + !(n & 1) - i)) V.push_back({i, j});
        }
    }
    printf("%d\n", V.size());
    for (auto p : V) printf("%d %d\n", p.first, p.second);
    return 0;
}