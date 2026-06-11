#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
using ll = long long;
int main() {
    int n;
    scanf("%d", &n);

    // |A1−(x+1)|+|A2−(x+1)|+⋯+|AN−(x+N)|をBi=Ai−i として式変形してくと|x−B1|+|x−B2|+⋯+|x−BN|になる
    vector<ll> a(n), b(n);
    rep(i, n) scanf("%lld", &a[i]), b[i] = a[i] - i;

    // |x-a|+|x-b|+|x-c|+...を最小にする x は、a,b,cが小さい順になっていたらその中央値
    sort(b.begin(), b.end());
    ll x = b[n / 2];

    ll res = 0;
    rep(i, n) res += max(x - b[i], -x + b[i]);  // |A| = max(A, -A)
    printf("%lld\n", res);
    return 0;
}