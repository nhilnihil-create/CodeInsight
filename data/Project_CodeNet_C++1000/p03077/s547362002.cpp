#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//ll GCD(ll x,ll y){
//    if(y == 0) return x;
//    else return GCD(y,x%y);
//}
const int MOD = 1000000007;


int main() {
    ll n;
    cin >> n;
    ll m = LLONG_MAX;
    for(int i = 0;i < 5;i++){
        ll a;
        cin >> a;
        m = min(m,a);
    }
    cout << ((n+m-1)/m)+4;
    
}


