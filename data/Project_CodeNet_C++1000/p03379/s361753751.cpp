#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main() {
    int n;
    scanf("%d", &n);

    vector<int> x(n);
    rep(i, n) scanf("%d", &x[i]);

    // 配列xのコピーを作って昇順
    vector<int> y(x);
    sort(y.begin(), y.end());

    // 中央値が2種類。
    // 中央からみて右側から要素を消した場合
    int right = y[n / 2 - 1];
    // 中央からみて左側から要素を消した場合
    int left = y[n / 2];

    rep(i, n) {
        int ans = (x[i] <= right) ? left : right;
        printf("%d\n", ans);
    }
    return 0;
}