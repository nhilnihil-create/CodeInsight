#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int f[100][10], p[100][11];
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) cin >> f[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 10; j++) cin >> p[i][j];
    }

    int ans = -1000000000;
    for (int i = 1; i < 1024; i++) {
        int tmp = 0;
        for (int j = 0; j < n; j++) {
            int count = 0;
            for (int k = 0; k < 10; k++) {
                if ((i & (1 << k)) && f[j][k] == 1) count++;
            }
            tmp += p[j][count];
        }
        if (tmp > ans) ans = tmp;
    }

    cout << ans << endl;
}
