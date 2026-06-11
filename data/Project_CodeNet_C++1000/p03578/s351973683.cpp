#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

int main(){
    ll n;
    cin >> n;
    map<ll, ll> l;
    rep(i, n){
        ll a;
        cin >> a;
        l[a]++;
    }
    ll m;
    cin >> m;
    vector<ll> o(m);
    rep(i, m) cin >> o[i];
    sort(o.begin(), o.end());
    bool z = true;
    rep(i, m){
        if(l.count(o[i]) && l[o[i]] > 0) l[o[i]]--;
        else{
            z = false;
            break;
        }
    }
    if(z) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}