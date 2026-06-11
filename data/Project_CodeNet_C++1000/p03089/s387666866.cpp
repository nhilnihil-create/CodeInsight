#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> b;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        if (t > i) {
            cout << -1 << endl;
            return 0;
        }
        b.insert(b.begin() + t - 1, t);
    }

    for (auto x:b) cout << x << endl;
    return 0;
}
