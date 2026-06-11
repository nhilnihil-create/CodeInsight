#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    double ans = 0;
    rep(i, n)
    {
        double x;
        string u;
        cin >> x >> u;
        if (u == "BTC")
            x *= 380000.0;
        ans += x;
    }
    printf("%.10f\n", ans);
    return 0;
}