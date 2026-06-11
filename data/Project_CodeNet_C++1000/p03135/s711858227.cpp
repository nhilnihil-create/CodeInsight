#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int t, x;
    cin >> t >> x;
    double ans = (double)t / x;
    printf("%.10f\n", ans);
    return 0;
}