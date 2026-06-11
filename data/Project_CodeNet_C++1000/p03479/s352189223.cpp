#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}
const int MOD = 1000000007;


int main() {
    ll x,y;cin >> x >> y;
    ll cnt = x;
    ll ans = 0;
    while(x <= y){
        ll a = 2;
        while(true){
            if(a*x%x==0){
                ans++;
                x = a*x;
                break;
            }else{
                a++;
            }
        }
    }
    cout << ans;
}


