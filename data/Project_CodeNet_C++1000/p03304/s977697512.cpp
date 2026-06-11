#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m, d;
    scanf("%lld%lld%lld", &n, &m, &d);
    double ans;
    if (d == 0) ans = (double)(m-1)/n;
    else ans = (double)((n-d)*2*(m-1))/(n*n);
    printf("%.10f\n", ans);
    return 0;
}