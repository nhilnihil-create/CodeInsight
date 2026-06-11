#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    long long n;
    while (cin >> n)
    {
        long long ans = 0;
        if (n < 3)
            cout << 0 << endl;
        else
        {
 
            for (long long i = 1; i * i <= n; i++)
            {
                if (n % i == 0)
                {
                    if (i != n / i && i + 1 != n / i) ans += n / i - 1;
                }
            }
            cout << ans << endl;
        }
    }
}