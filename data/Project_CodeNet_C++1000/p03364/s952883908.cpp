// https://atcoder.jp/contests/agc023/tasks/agc023_b
#include <bits/stdc++.h>
int n, t;
char s[305][305];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);
    for (int i = 0; i < n; i++) {
        bool ok = true;
        for (int j = 0; ok & j < n - 1; j++)
            for (int k = j + 1; ok & k < n; k++)
                if (s[(j + i) % n][k] != s[(k + i) % n][j])
                    ok = false;
        t += ok;
    }
    printf("%d\n", t * n);
}