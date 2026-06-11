#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int n, y;
    cin >> n >> y;
    bool flag = false;
    for (int i = 1; i <= n + 1; i++) {
        for (int j = i + 1; j <= n + 2; j++) {
            int sum = 10000 * (i - 1) + 5000 * (j - i - 1) + 1000 * (n + 2 - j);
            if (sum == y) {
                printf("%d %d %d\n", i - 1, j - i - 1, n + 2 - j);
                goto OUT;
            }
        }
    }
    printf("-1 -1 -1\n");
    OUT:
    return  0;
}