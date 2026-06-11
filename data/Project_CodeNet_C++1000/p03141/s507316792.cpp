//code by lynmisakura.wish to be accepted!
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void){
    int n;cin >> n;
    vector<ll> c(n);
    ll ans = 0;
    for(int i = 0;i < n;i++){
        ll a,b;cin >> a >> b;
        ans -= b;
        c[i] = a+b;
    }
    sort(c.begin(),c.end());
    reverse(c.begin(),c.end());
    for(int i = 0;i < n;i+=2){
        ans += c[i];
    }
    cout << ans << endl;
}
