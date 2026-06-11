#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

map<ll,ll> prime;
//素因数分解
void factor(ll x){
    for (ll i = 2; i<=sqrt(x); i++) {
        if(x%i==0){
            while(x%i == 0){
                x/=i;
                prime[i]++;
            }
        }
        if(x==1)break;
    }
    if(x != 0) prime[x]++;
}
int main(){
    ll n;
    cin >> n;
    ll ans = 0;

    for(ll i = 1; i <= n; i++){
        factor(i);
    }

    for(ll i = 2; i <= 98; i++){
        ll a = prime[i];
        if(a > 73) ans++;
        for(ll j = i+1; j <= 99; j++){
            ll b = prime[j];
            if(a > 3 && b > 13) ans++;
            if(b > 3 && a > 13) ans++;
            if(a > 1 && b > 23) ans++;
            if(b > 1 && a > 23) ans++;
            for(ll k = j+1; k <= 100; k++){
                ll c = prime[k];
                if(a > 1 && b > 3 && c > 3) ans++;
                if(b > 1 && a > 3 && c > 3) ans++;
                if(c > 1 && a > 3 && b > 3) ans++;
            }
        }
    }
    cout << ans << endl;
}