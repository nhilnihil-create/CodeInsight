#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long

using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
typedef pair<int, int> P;

int add(int x, int y) {
    if((x += y) >= mod) x -= mod;
    return x;
}

int mul(int x, int y) {
    LL z = (LL)x * y;
    return z - z / mod * mod;
}

int p[maxn], inv[maxn], pv[maxn];
int a[maxn], s[maxn], ls[maxn], rs[maxn];


int main() {
#ifdef TT
    freopen("xxx.in", "r", stdin);
#endif // TT
    int n, i, j, w = 0, u, dl, dr;
    scanf("%d", &n);
    for(i = 1;i <= n; i++) scanf("%d", &a[i]);
    for(i = p[0] = 1;i < maxn; i++) p[i] = mul(p[i - 1], i);
    inv[0] = inv[1] = 1;
    for(i = 2;i < maxn; i++) inv[i] = mul(mod - mod / i, inv[mod % i]);
    for(i = pv[0] = 1;i < maxn; i++) pv[i] = mul(pv[i - 1], inv[i]);
    for(i = 1;i <= n; i++) ls[i] = add(ls[i - 1], mul(a[i], i));
    for(i = 1;i <= n; i++) rs[i] = add(rs[i - 1], mul(a[n - i + 1], i));
    for(i = 1;i <= n; i++) s[i] = add(s[i - 1], a[i]);
    for(i = 0;i < n; i++) {
        if(i * 2 > n) j = n - i - 1;
        else j = i;
        u = add(ls[j], rs[j]);
        u = add(u, mul(j + 1, add(s[n - j], mod - s[j])));
        dl = s[i + 1];
        dr = add(s[n], mod - s[n - i - 1]);
        u = add(u, mod - dl);
        if(i + 1 != n) u = add(u, mod - dr);
        w = add(w, mul(mul(u, 2), mul(inv[i + 2], inv[i + 3])));
        if(i + 1 == n) w = add(w, dl);
        else w = add(w, mul(inv[i + 2], add(dl, dr)));
    }
    w = mul(w, p[n]);
    printf("%d\n", w);
    return 0;
}
