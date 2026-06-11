#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

ll gcd(ll a, ll b)
{
    ll x = max(a, b);
    ll y = min(a, b);
    if (x % y == 0)
    {
        return y;
    }
    else
    {
        gcd(y, x % y);
    }
}
int main()
{
    int x, y;
    cin >> x >> y;
    if(y == gcd(x,y)){
        cout << -1 << endl;
    }else{
        cout << x << endl;
    }
    return 0;
}