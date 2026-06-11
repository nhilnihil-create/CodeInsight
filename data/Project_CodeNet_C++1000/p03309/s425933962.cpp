#include <bits/stdc++.h>
using namespace std;

//long long型(64bit整数)
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    ll a[210000];
    for(ll i=0; i<n; i++){
        cin >> a[i];
        a[i] -= (i+1);
    }
    sort(a, a + n);
    ll ans = 0;
    for(ll i=0; i<n; i++){
        ans += abs(a[i] - a[n/2]);
    }
    cout << ans << endl;
    return 0;
}