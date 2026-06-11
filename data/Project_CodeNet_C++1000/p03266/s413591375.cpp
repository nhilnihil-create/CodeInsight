#include <bits/stdc++.h>

typedef long long   ll;
typedef long double ld;
using namespace std;

int main() {
    ll n,k;
    cin >> n >> k;
    ll tk=k;
    ll ans;
    if(k%2!=0){
        ll ca=n/k;
        ans=pow(ca,3);
    }
    else{
        ll cb=n/k;
        ll cc=n/(k/2)-cb;
        ans=pow(cb,3)+pow(cc,3);
    }
    cout << ans << "\n";
    return 0;
}