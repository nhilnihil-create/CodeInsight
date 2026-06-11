#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        if(a[i] >= b[n/2]) {
            cout << b[-1 + n/2] << "\n";
        }
        else {
            cout << b[n/2] << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
