#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

int main(){
    ll n; cin >> n;
    vector<ll> b(n), ans;
    rep(i, n) cin >> b[i];
    rep(i, n){
        ll index = -1;
        rep(j, b.size()) if(b[j] == j+1) index = j;
        if(index != -1){
            ans.push_back(b[index]);
            b.erase(b.begin()+index);
        }
    }
    if(!b.empty()){
        cout << -1 << endl;
        return 0;
    }
    reverse(ans.begin(), ans.end());
    for(auto i : ans) cout << i << endl;
    return 0;
}