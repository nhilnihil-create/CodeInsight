#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<double> pos(20);
    pos[0] = 1.0;
    for (int i = 1; i < 20; ++i)
        pos[i] = pos[i - 1] / 2;

    const double p = 1.0 / n;

    double ans = 0;

    for (int i = 1; i <= n; ++i)
    {
        int t = 0;
        while (i * (1 << t) < k)
            ++t;

        ans += p * pos[t];
    }
    printf("%.12lf\n", ans);
}