#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    int MAX = max({a, b, c});
    int sum = a + b + c;
    int ans = 0;

    // 3 * MAX に全ての数を揃えようとする。どの操作をしても総和は2ずつ増えるので3 * MAX - sumの偶奇によって操作が変わる。
    // 偶数だったら揃う。奇数だったら最大値を1加算して操作する。
    if((3 * MAX - sum) % 2 == 0) {
        ans = (3 * MAX - sum) / 2;
    }
    else ans = (3 * (MAX + 1) - sum) / 2;
    printf("%d\n", ans);
    return 0;
}