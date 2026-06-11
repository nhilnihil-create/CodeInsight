#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    long long ans = 0;
    ans = 0;
    if (k == 0)
    {
        ans = pow(n, 2);
    }
    else
    {
        for (int b = k + 1; b <= n; b++)
        {
            ans += (b - k) * (n / b) + max(0, n % b - (k - 1));
        }
    }
    cout << ans << endl;
    return 0;
}
