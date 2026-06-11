#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
    int n;
    scanf("%d", &n);
    double ans = 0;
    rep(i, n) {
        double x; string u;
        cin >> x >> u;
        if(u == "JPY") ans += x;
        else ans += x * 380000;
    }
    printf("%lf\n", ans);
    return 0;
}