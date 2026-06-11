#include<bits/stdc++.h>
#define fi first
#define se second
#ifdef CX_TEST
#define Debug printf
#else
#define Debug(...)
#endif
#define LL long long
#define UL unsigned long long
using namespace std;
typedef pair<int, int> P;
const int maxn = 2e5 + 5;

LL x[maxn];

int main() {
#ifdef CX_TEST
    freopen("E:\\program--GG\\test_in.txt", "r", stdin);
#endif
    int n, i, j, k;
    UL ans = -1, w, res;
    scanf("%d", &n);
    scanf("%llu", &w);
    for(i = 1; i <= n; i++) scanf("%lld", &x[i]);
    for(i = 1; i <= n; i++) x[i] += x[i - 1];
    for(i = 1; i <= n; i++) {
        if(i * 2 >= n) {
            ans = min(ans, (UL)x[n] * 5 + w * i);
            break;
        }
        res = (x[n] - x[n - i * 2]) * 5 + w * i;
        for(j = n - i * 2, k = 7; j > 0; j -= i, k += 2) res += (x[j] - x[max(j - i, 0)]) * k;
        ans = min(ans, res);
    }
    cout << ans + n * w << endl;
    return 0;
}
