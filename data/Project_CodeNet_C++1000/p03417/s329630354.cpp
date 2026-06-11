#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll n, m;
    scanf("%lld%lld", &n, &m);
    ll ans = 0;
    // 偶数回裏返すと表、奇数回裏返すと裏
    // 制約n <= m
    // N = 1 かつ M = 1 のとき
    if(n == 1 && m == 1) {
       ans = 1;
    }
    // 行、列、一方に長い行列。長い方の両端以外が裏になる。
    else if(n == 1 || m == 1) {
        ans = max(n, m) - 2;
    }
    // N >= 2 かつ N <= M かつ M >= 2
    // 四隅は4回、四隅以外の端は6回、それ以外は9回
    else {
        // ans = n * m - (2 * (n + m) - 4);
        ans = (n - 2) * (m - 2); 
    }
    printf("%lld\n", ans);
    return 0;
}
