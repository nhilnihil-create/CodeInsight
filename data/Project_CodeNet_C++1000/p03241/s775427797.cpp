#include<bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> divisor(ll n){
    std::vector<ll> res;
    for(ll i = 1LL; i * i <= n; i++){
        if(n % i == 0){
            res.push_back(i);
            ll j = n / i;
            if(i != j)res.push_back(j);
        }
    }
    std::sort(res.begin(),res.end(), greater<ll>());
    return res;
}


int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> div = divisor(m);
    for(auto i : div) {
        if(m / i >= n) {
            cout << i << endl;
            return 0;
        }
    }
}