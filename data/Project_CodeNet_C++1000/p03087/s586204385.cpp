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
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector<int> cum(n + 1, 0);
    for (int i = 0; i < n - 1; i++)
    {
        if (s.substr(i, 2) == "AC" && i < n - 1)
        {
            cum[i + 2] = cum[i + 1] + 1;
        }
        else
        {
            cum[i + 2] = cum[i + 1];
        }
    }

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << cum[r] - cum[l] << '\n';
    }

    return 0;
}
