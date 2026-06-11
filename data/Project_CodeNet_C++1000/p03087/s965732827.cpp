#include <bits/stdc++.h>
using namespace std;

void solve () {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> a(n);
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == 'A' && s[i] == 'C') {
            sum++;
        }
        a[i] = sum;
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << a[r - 1] - a[l - 1] << "\n";
    }

        
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
