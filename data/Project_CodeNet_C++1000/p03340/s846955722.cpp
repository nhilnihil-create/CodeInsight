#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
const int MAXN = 200005;
int n;
LL a[MAXN], sum[MAXN], sumxor[MAXN];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    sum[1] = sumxor[1] = a[1];
    for (int i = 2; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
        sumxor[i] = sumxor[i - 1] ^ a[i];
    }
    LL ans = 0;
    int l = 1;
    for (int r = 1; r <= n; r++) {
        while ((sum[r] - sum[l - 1]) != (sumxor[r] ^ sumxor[l - 1])) l++;
        ans += r - l + 1;
    }
    printf("%lld\n", ans);
    return 0;
}