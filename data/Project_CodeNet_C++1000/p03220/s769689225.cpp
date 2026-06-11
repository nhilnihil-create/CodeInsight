#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, t;
    double a;
    cin >> n;
    cin >> t >> a;
    double h[n];
    for (double &i : h)
    {
        int tmp;
        cin >> tmp;
        i = t - tmp * 0.006;
    }
    double min = abs(h[0] - a), ans(1);
    for (int i = 1; i < n; ++i)
    {
        if (abs(h[i] - a) < min)
        {
            min = abs(h[i] - a);
            ans = i + 1;
        }
    }
    cout << ans << endl;
}