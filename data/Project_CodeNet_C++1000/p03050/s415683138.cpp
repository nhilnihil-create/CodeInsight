#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;

    ll ans = 0;
    vector<ll> a;

    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0){
            ll k = n / i;
            a.push_back(i);
            a.push_back(k);
        }
    }

    for(int i = 0; i < a.size(); i++){
        if(a[i] != 1){
            if(n % (a[i] - 1) == n / (a[i] - 1)){
                ans += a[i] - 1;
            }
        }
    }

    cout << ans << endl;
}