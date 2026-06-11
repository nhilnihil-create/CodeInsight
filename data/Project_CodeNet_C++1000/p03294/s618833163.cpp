#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, a;
    scanf("%d", &n);
    ll ans = 0;    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        ans += a;
    }
    ans -= n;
    printf("%lld", ans);
    return 0;
}