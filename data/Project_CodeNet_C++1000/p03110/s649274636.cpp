#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;

    double ans = 0;
    rep (i, n)
    {
        double x;
        string u;
        cin >> x >> u;
        if (u[0] == 'J')
            ans += x;
        else
            ans += 380000 * x;
    }

    printf("%.6f\n", ans);
    return 0;
}