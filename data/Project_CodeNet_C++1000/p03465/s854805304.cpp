#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int e = 4*1e6 + 69;
const int mod = 1e9 + 7;

ll a[e];
bitset<e>bits;

int main()
{
    ll n;
    cin >> n;
    bits[0] = 1;
    for(int i=1; i<=n; i++)
    {
        ll x;
        cin >> x;
        bits |= (bits << x);
    }
    ll dem = 0;
    for(int i=1; i<=e; i++)
    {
        if(bits[i])
        {
            dem ++;
            a[dem] = i;
        }
    }
    cout << a[(dem + 1)/2];

}
