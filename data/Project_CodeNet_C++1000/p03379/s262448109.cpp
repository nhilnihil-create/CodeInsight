#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

int main(){
    ll n;
    cin >> n;
    vector<ll> x1(n), x2(n);
    rep(i, n){
        cin >> x1[i];
        x2[i] = x1[i];
    }
    sort(x2.rbegin(), x2.rend());
    ll median = x2[n/2-1];
    rep(i, n){
        if(x1[i] >= median){
            cout << x2[n/2] << endl;
        }
        else{
            cout << median << endl;
        }
    }
    return 0;
}