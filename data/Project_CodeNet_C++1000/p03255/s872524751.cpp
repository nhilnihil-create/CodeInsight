#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long

using namespace std;

int D[1000010], S[1000010];

int n, X, Ans = 1e18;

int mul(int a, int b) {
    if(a && (int) 2e18 / a < b) return 2e18;
    return a * b;
}
signed main() {
    scanf("%lld%lld", &n, &X);
    for(int i = 1; i <= n; i++) scanf("%lld", &D[i]), S[i] = S[i - 1] + D[i];
    for(int i = 1; i <= n; i++) {
        int cnt = 0, s = 0, ans = 0, q = 0;
        ans += n * X;
        ans += 2 * (S[n] - S[n - i]);
        ans += i * X;
        for(int j = n, f = 0; j >= 1; f++, j -= i) {
            int l = 2 * f + 3;
            if(j > i) ans += mul(l, (S[j] - S[j - i] - i * D[j - i])) + mul(q, (D[j] - D[j - i])); else ans += mul(l, S[j]) + mul(q, D[j]);
            q += l * i;
            if(ans > 1e18) break;
        }
        if(ans < Ans) Ans = ans;
    }
    printf("%lld\n", Ans);
    return 0;
}