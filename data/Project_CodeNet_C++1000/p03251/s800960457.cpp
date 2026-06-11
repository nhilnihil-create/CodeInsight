#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> xs(n), ys(m);
    for (int i=0; i<n; ++i) cin >> xs[i];
    for (int i=0; i<m; ++i) cin >> ys[i];
    sort(xs.begin(), xs.end(), greater<int>());
    sort(ys.begin(), ys.end());
    bool ans = false;
    for (int i=xs[0]+1; i<=ys[0]; ++i) {
        if (x < i && i <= y) ans = true;
    }
    cout << (ans ? "No War" : "War") << endl;
}