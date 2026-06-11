#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){

    // input
    ll n;
    cin >> n;
    vector<pair<ll,ll>> b(n);
    rep(i, 0, n){
        cin >> b[i].first;
        b[i].second = i+1;
    }
    vector<ll> res(n);
    rep(i, 0, n) {
        ll cur = n - i;
        bool f = true;
        for(ll j = n-1; j >= 0; j--) {
            if(b[j].first == cur) {
                b[j].second = -1;
                for(ll k = j+1; k < n; k++) {
                    b[k].second--;
                }
                res[i] = b[j].first;
                f = false;
                break;
            }
            if(b[j].second >= 0) cur--; 
        }
        if(f) {
            cout << -1 << endl;
            return 0;
        }
    }
    for(ll i = n-1; i >= 0; i--) cout << res[i] << endl;
    return 0;
}