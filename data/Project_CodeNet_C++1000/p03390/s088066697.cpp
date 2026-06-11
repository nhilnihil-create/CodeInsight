#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int maxn = 105;
int q;
const long double eps = 1e-9;

int main()
{
    scanf("%d", &q);
    for(int i = 0; i < q; i ++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if(a > b)
            swap(a, b);

        long double t = (long double) a * (long double) b - 1 ;
        long double sqt = floorl(sqrtl(t));
        long double ans = 2 * sqt;
        if(fabsl(floorl(t / sqt) - sqt) <= eps)
            ans -= 1.0;
        if(a - sqt <= 0.0 )
            ans -= 1.0;
        printf("%.0Lf\n", ans);
    }
    return 0;
}
