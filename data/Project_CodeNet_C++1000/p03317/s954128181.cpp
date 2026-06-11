#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    // 1からはじまる配列なので、全部1にする
    // 1要素かぶらせる形でk個分の区間でnを埋めてく
    // 配列aに関係なく、kの区間の数が答え
    // a / b の切り上げは、(a + (b - 1)) / b
    // 既に1が一個あるのでa = n - 1。重ねる分b = k - 1。
    int ans = (n - 1 + k - 2) / (k - 1);
    printf("%d\n", ans);
    return 0;
}