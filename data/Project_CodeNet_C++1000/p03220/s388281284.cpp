#include <bits/stdc++.h>
using namespace std;

bool is_square(int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (i * i == n)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n, t, a;
    cin >> n >> t >> a;
    double min_diff = 100000;
    int ans = 0;
    for (size_t i = 0; i < n; i++)
    {
        int h;
        cin >> h;
        double temp = t - h * 0.006;
        if (abs(a - temp) < min_diff)
        {
            ans = i;
            min_diff = abs(a - temp);
        }
    }
    cout << ans + 1 << endl;

    return 0;
}