#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b)
{
    if(b == 0) return a;
    return gcd(b, a%b);
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll s = a - b;
        if(s < 0 || b > d)
        {
            cout << "No" << endl;
            continue;
        }
        if(c+1 >= b)
        {
            cout << "Yes" << endl;
            continue;
        }
        ll x = gcd(b, d);
        ll out = b - x + s%x;
        if(out > c) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}
