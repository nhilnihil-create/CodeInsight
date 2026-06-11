#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, c;
    cin >> n >> m >> c;
    int b[m];
    int a[n][m];
    int i;
    for(i = 0; i < m; i++) {
        cin >> b[i];
    }
    int j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int cnt = 0;
    int ans = 0;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            ans += a[i][j] * b[j];
        }
        if (ans + c > 0) {
            cnt++;
        }
        ans = 0;
    }
    cout << cnt << endl;
}
