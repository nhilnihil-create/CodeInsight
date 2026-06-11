#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin>>n;

    ll small = 2;
    ll big = 1;
    ll ans =0;
    if( n ==1)
        cout<<1;
    else {
        for (int i = 2; i <= n; i++) {
            ans = small + big;
            small = big;
            big = ans;
        }
        cout << ans;
    }
}