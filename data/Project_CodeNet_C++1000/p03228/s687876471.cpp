#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define int ll
#define all(v) v.begin(), v.end()
#define reps(__i, a, b) for (int __i = a; i < b; i++)
#define rep(__i, n) reps(__i, 0, n)

const ll INF = (1ll << 60);
const ll MOD = (ll)1e9 + 7;

signed main()
{
    int a, b, k;
    cin >> a >> b >> k;

    for (int i = 0; i < k; i++)
    {
        if (i % 2 == 0)
        {
            if (a % 2)
            {
                a--;
            }
            b += a / 2;
            a /= 2;
        }
        else
        {
            if (b % 2)
            {
                b--;
            }
            a += b / 2;
            b /= 2;
        }
    }
    cout << a << " " << b << endl;
}