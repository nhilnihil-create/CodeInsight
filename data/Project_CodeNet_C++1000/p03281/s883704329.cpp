#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int divisors(int n)
{
    int ret = 0;
    for (int i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            ret++;
            if (n / i != i)
                ret++;
        }
    }
    return ret;
}

int main()
{
    int n;
    cin >> n;

    int ans = 0;
    rep (i, n + 1)
        if (divisors(i) == 8 && i % 2 == 1)
            ans++;

    cout << ans << endl;
    return 0;
}