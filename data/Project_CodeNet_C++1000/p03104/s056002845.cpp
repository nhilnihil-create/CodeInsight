#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

ll calc(ll a){
    if(a == -1) return 0;
    if(a == 0) return 0;
    if(a == 1) return 1;
    if(a%2==0){
        if((a / 2) % 2 == 0) return a^0;
        else return a^1;
    }else{
        if(((a-1)/2) %2== 0) return a^(a-1)^0;
        else return a^(a-1)^1;
    }
}

int main(){
    ll a, b;
    cin >> a >> b;
    a = calc(a - 1);
    b = calc(b);
    ll ans = a^b;
    cout << ans << endl;
    return 0;
}