#include <bits/stdc++.h>
using namespace std;

int n;
char s[310][310], t[310][310];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        bool flag = 1;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                t[j][k] = s[j][(k + i) % n];
            }
        }
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                flag &= t[j][k] == t[k][j];
            }
        }
        if (flag) ans += n;
    }
    printf("%d\n", ans);
    return 0;
}