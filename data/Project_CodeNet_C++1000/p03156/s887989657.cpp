#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    ll a,b;
    cin >> a >> b;
    ll A=0,B=0,C=0;
    for(ll i=0;i<n;i++){
        ll p;
        cin >> p;
        if(p<=a) A++;
        else if(p<=b) B++;
        else C++;
    }
    ll ans=min(min(A,B),C);
    cout << ans << endl;
}
