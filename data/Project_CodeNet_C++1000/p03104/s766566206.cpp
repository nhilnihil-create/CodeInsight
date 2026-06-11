#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = unsigned long long;


ll f(ll x) {
    x++;
    ll res = 0;
    // 1の位
    if ((x/2) % 2 != 0) res += 1;

    // それより上の位
    ll order = 1;
    while (true) {
        
        order++;
        ll y = ((1ULL)<<order);
        ll r = x%y;
        y/=2;
        if (x < y) break;
        if (r < y) continue;
        else {
            if((r-y)%2 != 0) res += y;
        }
    }

    return res;
}


int main() 
{
    ll a, b;
    cin >> a >> b;
    ll ans = f(b) ^ f(a-1);
    cout << ans << endl;


    return 0;
}
