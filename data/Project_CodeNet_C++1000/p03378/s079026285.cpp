#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a.at(i);
    }
    auto bound = lower_bound(a.begin(), a.end(), x);
    if (bound == a.begin()) {
        cout << 0 << endl;
        return 0;
    }
    cout << min(bound  - a.begin(), a.end() - bound) << endl;
    return 0;
}