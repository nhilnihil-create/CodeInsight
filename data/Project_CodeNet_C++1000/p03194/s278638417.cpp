#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;
typedef long long ll;
int main(void){
    ll n,p,a[1000010] = {},ans = 1;
    cin >> n >> p;
    if(n == 1){
        cout << p << endl;
        return 0;
    }
    if(n <= 12){
    for(ll i = 2;i <= pow(10,12/n)+10;i++){
        ll k = i;
        while(p % k == 0){
            p /= k;
            a[i]++;
        }
        if(p == 1) break;
    }
    for(ll i = 2;i <= pow(10,12/n)+10;i++){
        ll tmp = (a[i]/n);
        if(tmp >= 1) ans *= pow(i,tmp);
    }
    cout << ans << endl;
    return 0;
    }
    
    for(ll i = 2;i <= 7;i++){
        ll k = i;
        while(p % k == 0){
            p /= k;
            a[i]++;
        }
        if(p == 1) break;
    }
    for(ll i = 2;i <= 7;i++){
        ll tmp = (a[i]/n);
        if(tmp >= 1) ans *= pow(i,tmp);
    }
    cout << ans << endl;
    return 0;
}
