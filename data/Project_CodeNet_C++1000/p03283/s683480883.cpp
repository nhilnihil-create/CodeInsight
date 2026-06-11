#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll s[505][505];

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0, l, r; i < m; i++) {
        cin >> l >> r;
        l--; r--;
        s[l][r]++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            s[i][j] += s[i][j - 1];
        }
    }
    for (int j = 0; j < n; j++) {
        for (int i = n - 2; i >= 0; i--) {
            s[i][j] += s[i + 1][j];
        }
    }
    for (int i = 0, l, r; i < q; i++) {
        cin >> l >> r;
        l--; r--;
        cout << s[l][r] << endl;
    }
}