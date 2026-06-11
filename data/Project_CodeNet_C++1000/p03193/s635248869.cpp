#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;
int main()
{
    ll n,h,w;
    cin >> n >> h >> w;
    ll ans = 0;
    for(ll i = 0;i < n;i++)
    {
        ll a,b;
        cin >> a >> b;
        if(a >= h && b >= w)
        {
            ans++;
        }
    }
    cout << ans << "\n";
    
    return 0;
}