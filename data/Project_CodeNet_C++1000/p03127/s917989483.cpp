#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
int main()
{
    ll n , gcd , x;
    cin >> n;
    for(ll i = 0 ; i < n ; i++)
    {
        cin >> x;
        if(!i) 
            gcd = x;
        gcd = __gcd ( x , gcd);
    }
    cout << gcd << endl;
    return 0;
}