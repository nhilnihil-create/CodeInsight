#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

vector<ll> comdiv(ll x){
    vector<ll> res;
    stack<ll> big;
    for(ll i = 1; i*i <= x; i++){
        if(x%i == 0){
            res.push_back(i);
            big.push(x/i);
        } 
    }
    while(!big.empty()){
            res.push_back(big.top());
            big.pop();
    }
    return res;
}

int main(){
    ll n;
    cin >> n;
    vector<ll> li = comdiv(n);
    ll ans = 0;
    if(n == 1){
        cout << ans << endl;
        return 0;
    }
    li.erase(li.begin());
    for(auto p:li){
        p--;
        if((n/p) == n%p) ans += p;
    }
    cout << ans << endl;
    return 0;
}