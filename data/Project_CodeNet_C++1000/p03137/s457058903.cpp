#include <bits/stdc++.h>
using namespace std;

void solve () {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    if (n >= m) {
        cout << 0;
        return;
    }
    sort(a.begin(), a.end());
    vector<int> dif(m - 1);
    for (int i = 1; i < m; i++) {
        dif[i - 1] = a[i] - a[i - 1];
    }
    sort (dif.rbegin(), dif.rend());
    long long sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += dif[i];
    }
    cout << accumulate(dif.begin(), dif.end(), 0) - sum;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
