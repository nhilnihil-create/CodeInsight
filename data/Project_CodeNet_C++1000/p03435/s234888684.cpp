#include <bits/stdc++.h>

using namespace std;

int c[4][4];

void solve() {
    int a[4] = {0}, b[4] = {0};
    for (int i = 0; i < 100; ++i) {
        a[1] = i;
        b[1] = c[1][1] - a[1];
        a[2] = c[2][1] - b[1];
        b[2] = c[2][2] - a[2];
        a[3] = c[3][2] - b[2];
        b[3] = c[3][3] - a[3];
        bool flag = true;
        for (int j = 1; j <= 3; j++) {
            for (int k = 1; k <= 3; k++) {
                if (c[j][k] != a[j] + b[k]) {
                    flag = false;
                }
            }
        }
        if (flag) {
            printf("Yes\n");
            return;
        }
    }
    printf("No\n");
}

int main() {
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            cin >> c[i][j];
        }
    }
    solve();
    return 0;
}
