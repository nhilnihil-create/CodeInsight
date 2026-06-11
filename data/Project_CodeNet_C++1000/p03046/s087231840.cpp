#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
#define lcm(x, y) ((x) * (y) / __gcd((x), (y)))
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define debug(x) cout << #x << " : " << x << endl
#define part cout << "----------------------------------\n";
#include <iostream>

#define fastinput                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

LL POW(LL x, LL y)
{
    LL ans = 1;
    LL base = x;
    while (y)
    {
        if (y & 1)
        {
            ans *= base;
        }
        base = base * base;
        y = y >> 1;
    }
    return ans;
}

int main()
{
    fastinput;
    LL n, i, j, k, t, temp, tc;
    LL M;
    cin >> M >> k;
    LL limit = POW(2, M) - 1;
    short freq[limit + 1] = {0};
    if (k > limit)
    {
        cout << -1 << endl;
    }
    else
    {
        if (M == 0)
        {
            if (k == 0)
            {
                cout << "0 0" << endl;
            }
        }
        else if (M == 1)
        {
            if (k == 0)
            {
                cout << "1 0 0 1" << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else
        {

            for (i = 0; i <= limit; i++)
            {
                if (i != k)
                {
                    cout << i << " ";
                }
            }
            cout << k << " ";
            for (i = limit; i >= 0; i--)
            {
                if (i != k)
                {
                    cout << i << " ";
                }
            }
            cout << k << " ";
        }
    }
    return 0;
}
