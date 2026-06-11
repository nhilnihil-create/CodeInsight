#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll sqint(ll num){

    ll l = 0;
    ll r = 1e10;

    while(r - l > 1){
        ll mid = (r + l) / 2;
        (mid * mid <= num ? l : r) = mid;
    }
    return l;
}


int main()
{
    int n;
    cin >> n;
    cout << sqint(n) * sqint(n) << endl;
}