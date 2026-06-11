#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
using ll = long long;
int main() {
    int n;
    scanf("%d", &n);
    
    ll sum = 0;
    rep(i, n) {
        ll a; scanf("%lld", &a);
        sum += a;
    }

    // a-1を足してけばいい = 合計からaの合計個数nを引いてる
    printf("%lld", sum - n);
    return 0;
}