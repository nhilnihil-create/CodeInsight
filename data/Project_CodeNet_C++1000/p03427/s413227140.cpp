#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
    ll n;
    cin >> n;
    ll m = n;
    bool f = true;
    while (m >= 10)
    {
        if (m % 10 != 9)
        {
            f = false;
            break;
        }
        m /= 10;
    }
    if (f)
    {
        if (n < 10)
        {
            cout << n << endl;
        }
        else
        {
            int sum = 0;
            while (n >= 10)
            {
                sum += 9;
                n /= 10;
            }
            cout << sum + n << endl;
        }
    }
    else
    {
        int sum = 0;
        while (n >= 10)
        {
            sum += 9;
            n /= 10;
        }
        cout << sum + n - 1 << endl;
    }

    return 0;
}