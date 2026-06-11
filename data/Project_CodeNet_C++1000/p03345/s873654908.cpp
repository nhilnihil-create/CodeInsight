#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
const int MOD = 1e9+7;

ll power(ll a, ll b){
    ll r=1;
    while(b>0){
        if(b&1)
            r=r*a %MOD;
        a = a*a %MOD;
        b/=2;
    }
    return r;
}

int main(){
    ull a, b, c, k;
    cin >> a >> b >> c >> k;
    ll ans;
    if(k&1)
        ans = b-a;
    else
        ans = a-b;

    cout << ans;
}
