#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

int main(){
    ll n;
    cin >> n;
    map<ll, ll> a;
    rep(i, n){
        ll an;
        cin >> an;
        a[an]++;
    }
    ll ans = 0;
    for(auto i : a){
        if(i.second < i.first) ans += i.second;
        else if(i.second > i.first) ans += i.second - i.first;
    }
    cout << ans << endl;
    return 0;
}