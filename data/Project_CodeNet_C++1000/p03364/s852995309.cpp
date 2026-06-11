// https://atcoder.jp/contests/agc023/tasks/agc023_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t = 0;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
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