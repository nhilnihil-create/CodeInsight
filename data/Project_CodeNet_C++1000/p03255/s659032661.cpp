#include <bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;
const int maxn = 2e5 + 7;
LL tmp, X, sum[maxn];
int n;
int main()
{
    scanf("%d%lld", &n, &X);
    sum[0] = 0;
    double ans = 1e60;
    for(int i = 1; i <= n; i++) scanf("%lld", &tmp), sum[i] = sum[i - 1] + tmp;
    for(int k = 1; k <= n; k++)
    {
        double Tmp = 0;
        for(int i = n; i >= 0; i -= k)
        {
            if(i == n) Tmp += 5 * sum[i];
            else if(i + k == n) continue;
            else Tmp += 2 * sum[i];
        }
        Tmp += (k + n) * X;
        ans = min(ans, Tmp);
    }
    printf("%lld", (LL)ans);
    return 0;
}
