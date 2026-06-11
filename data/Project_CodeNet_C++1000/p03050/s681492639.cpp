#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> enumDivisor(ll n){
    vector<ll> res;
    for(ll i = 1; i * i <= n; i++){
        if(n % i != 0) continue;
        res.push_back(i);
        if(i * i != n)
            res.push_back(n / i);
    }
    return res;
}

int main(){
    ll n;
    cin >> n;
    ll ans = 0;
    for(auto x : enumDivisor(n)){
        if(x == 1) continue;
        if(n / (x-1) == n % (x-1))
            ans += x-1;
    }
    cout << ans << endl;
    return 0;
}