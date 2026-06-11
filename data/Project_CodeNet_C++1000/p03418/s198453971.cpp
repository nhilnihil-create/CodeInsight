#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n,k;
    cin >> n >> k;
    ll b=k+1;
    ll a=k;
    ll ans=0;
    while(b<=n){
        while(a<=n){
            if(a==0) ans--;
            if(a+b<=n) ans+=(b-k);
            else ans+=min(b-k,n-a+1);
            a+=b;
        }
        a=k;
        b++;
    }
    cout << ans << endl;
}