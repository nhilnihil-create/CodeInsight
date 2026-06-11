#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int a, h, n, w;
    cin >> a;
    for (h = 1; h <= 4500; ++h)
        for (n = 1; n <= 4500; ++n)
            if (4 * h * n - a * (n + h) && a * h * n % (4 * h * n - a * (n + h)) == 0)
            {
                w = a * h * n / (4 * h * n - a * (n + h));
                if (w > 0)
                {
                    cout << h << " " << n << " " << w << endl;
                    return 0;
                }
            }
    return 0;
}