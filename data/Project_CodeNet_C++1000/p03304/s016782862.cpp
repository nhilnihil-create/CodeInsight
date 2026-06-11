#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, d;
    scanf("%d%d%d", &n, &m, &d);
    long double ans = n-d;
    if(d != 0) ans *= 2;
    ans /= n*1ll*n;
    ans *= m-1;
    printf("%.10Lf\n", ans);
}