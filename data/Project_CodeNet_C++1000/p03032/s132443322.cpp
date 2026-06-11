#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];
    ll ans = 0;
    for(ll l = 0; l < k + 1; l++){
        for(ll r = 0; r < k - l + 1; r++){
            if(l + r > n) continue;
            vector<ll> s = {};
            ll memo = 0;
            rep(i, l){
                memo += v[i];
                s.push_back(v[i]);
            }
            rep(i,r){
                memo += v[n - i - 1];
                s.push_back(v[n - i - 1]);
            }
            sort(s.begin(), s.end());
            rep(i, k - l - r){
                if(i >= s.size()) break;
                if(s[i] > 0) break;
                memo -= s[i];
            }
            ans = max(ans, memo);
        }
    }
    cout << ans << endl;
    return 0;
}