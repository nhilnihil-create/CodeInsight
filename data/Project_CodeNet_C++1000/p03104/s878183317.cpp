#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll XOR(ll n)
{
    ll mod = n % 4;
    if (mod == 0) return n;
    else if (mod == 1) return 1;
    else if (mod == 2) return n + 1;
    else if (mod == 3) return 0;
}
ll XOR(ll l, ll r)
{
    return (XOR(l - 1) ^ XOR(r));
}
int main()
{
    long long  l , r ;
    cin>>l>>r;
    cout << XOR(l, r);

    return 0;
}
