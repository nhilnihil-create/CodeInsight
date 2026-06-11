#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;
int main()
{
    ll a,b,k;
    cin >> a >> b >> k;
    for(ll i = 0;i < k;i++)
    {
        if(i % 2 == 0)
        {
            if(a % 2 == 1)
            {
                a--;
            }
            a /= 2;
            b += a;
        }
        else
        {
            if(b % 2 == 1)
            {
                b--;
            }
            b /= 2;
            a += b;
        }
    }
    cout << a << " " << b << "\n";
    
    return 0;
}