#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll x, y;
    scanf("%lld%lld", &x, &y);

    // Ai+1はAiの倍数であり、かつAi+1はAiより真に大きい
    // Ai+1はAiの2倍のとき、配列の要素数を一番多くできる
    ll ans = 0;
    while(x <= y) {
        ans++;
        x *= 2;
    }
    printf("%lld\n", ans);
    return 0;
}