#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n)
{
    if (n == 0 || n == 1)
        return (false);
    if (n % 2 == 0 && n != 2)
        return (false);
    for (int i = 3; i * i < n + 1; i += 2)
    {
        if (n % i == 0)
        {
            return (false);
        }
    }
    return (true);
}

int main()
{
    int q;
    cin >> q;
    vector<int> cum(1e5 + 1, 0);
    for (int i = 0; i < 1e5 + 1; i++)
    {
        if (is_prime(i) && is_prime((i + 1) / 2) && i % 2 == 1)
        {
            cum[i + 1] = cum[i] + 1;
        }
        else
        {
            cum[i + 1] = cum[i];
        }
    }

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << cum[r + 1] - cum[l] << '\n';
    }
}
