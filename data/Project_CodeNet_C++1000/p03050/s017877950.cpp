#include<iostream>
#include<set>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll i = 1; i*i <= n; i++){
        if(n%i) continue;
        ll m = n/i-1;
        if(m > 0 && n/m == n%m)   ans += m;
        if(i == n/i)    continue;
        m = i-1;
        if(m > 0 && n/m == n%m) ans += m;
    }
    cout << ans << endl;
    return 0;
}