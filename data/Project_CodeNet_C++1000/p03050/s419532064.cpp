#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;

    ll ans=0;
    for(ll i = 1; i*i <= n; i++) {
        if(n%i==0 && n/i-1>i) ans+=n/i-1;
    }
    cout << ans << "\n";

    return 0;
}