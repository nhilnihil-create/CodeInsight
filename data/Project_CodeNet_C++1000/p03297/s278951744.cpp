#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void solve(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if(b > a){
        cout << "No\n";
        return;
    }
    if(b > d){
        cout << "No\n";
        return;
    }
    ll nzd = __gcd(b, d);
    ll x = a%nzd;
    ll k = c-b+1;
    if(k >= 0){
        cout << "Yes\n";
        return;
    }
    if(abs(k) >= nzd){
        cout << "No\n";
        return;
    }
    if(nzd-x <= -k) cout << "No\n";
    else cout << "Yes\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
