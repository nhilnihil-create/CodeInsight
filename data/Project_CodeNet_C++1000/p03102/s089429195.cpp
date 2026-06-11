#include<iostream>
using namespace std;

int main() {
    int n, m, c;
    int a[30][30], b[30];
    int ans = 0;
    cin >> n >> m >> c;
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }

    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < m; j++) {
            sum += a[i][j] * b[j];
        }
        if (sum + c > 0) ans++;
    }

    cout << ans << endl;
}
