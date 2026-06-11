#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;

#define INF (long long)(10e9+7)
#define REP(i,n) for(ll i = 0; i < n; i++)

int main(void)
{
    ll a,b,c,x,y,xy,p;
    ll res = INF;
    cin >> a >> b >> c >> x >> y;
    xy = max(x,y);
    for(ll i = 0; i <= xy; i++) {
        p = c * i * 2;
        p += a * max(x - i, (ll)0);
        p += b * max(y - i, (ll)0);
        res = min(res, p);
    }
    cout << res << endl;
}
