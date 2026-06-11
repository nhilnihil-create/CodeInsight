#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll = long long int;

unordered_map<ll, ll> m;

ll lucas(ll n)
{
    if(n == 0)
        return 2;

    if(n == 1)
        return 1;
    
    ll l, r;
    
    if(m[n-1])
        l = m[n-1];
    else
    {
        l = lucas(n - 1);
        m[n-1] = l;
    }

    if(m[n-2])
        r = m[n-2];
    else
    {
        r = lucas(n - 2);
        m[n-2] = r;
    }

    return l + r;
}

int main()
{
    ll n;
    cin >> n;

    cout << lucas(n) << "\n";
    return 0;
}