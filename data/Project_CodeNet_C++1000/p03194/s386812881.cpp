#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<pair<ll, ll>> prime_factorize(ll n){
    vector<pair<ll, ll>> res;
    for(ll p = 2; p * p <= n; p++){
        if(n % p != 0) continue;
        int num = 0;
        while(n % p == 0){ num++; n /= p;}
        res.push_back(make_pair(p, num));
    }
    if(n != 1) res.push_back(make_pair(n, 1));
    return res;
}

int main(){
    ll n, p;
    cin >> n >> p;
    auto v = prime_factorize(p);
    ll ans = 1;
    for(int i = 0; i < v.size(); i++){
        if(v[i].second / n == 0) continue;
        ans *= pow(v[i].first, v[i].second / n);
    }
    cout << ans << endl;
    return 0;
}
