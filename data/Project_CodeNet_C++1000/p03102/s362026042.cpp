#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> b(m);
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int counter = c;
        for(int j = 0; j < m; j++) {
            counter += a[i][j] * b[j];
        }
        if(counter > 0) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}