#include <bits/stdc++.h>
using namespace std;
#define __Mammamia__                ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        200007

int main()
{
    ll n, k, res = (ll)0; cin >> n >> k;

    if(!k){cout << n * n << endl; return 0;}

    for(ll i = 1; i <= n; ++i)
    {
        if(i > k)
        {
            res += (n / i) * (i - k) + max((ll)0, (n % i - k + 1));
        }
    }
    cout << res << endl;

    return 0;
}




