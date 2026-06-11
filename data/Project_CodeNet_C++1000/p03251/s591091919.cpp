#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int mx = -1001001001;
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        mx = max(mx, p);
    }
    int my = 1001001001;
    for (int j = 0; j < m; ++j) {
        int p;
        cin >> p;
        my = min(my, p);
    }
    bool ans = true;
    for (int z = x + 1; z <= y; ++z) {
        if (mx < z && my >= z) {
            ans = false;
            break;
        }
    }
    cout << (ans ? "War" : "No War") << endl;
}
