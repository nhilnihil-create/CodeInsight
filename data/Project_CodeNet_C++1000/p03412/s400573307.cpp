#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;

ll num(const vector<ll> &v, ll low, ll up, ll a){
    ll left = lower_bound(v.begin(), v.end(), low - a) - v.begin();
    ll right = lower_bound(v.begin(), v.end(), up - a) - v.begin();
    return right - left;
}

int main(){
    ll N;
    cin >> N;
    vector<ll> a(N), b(N);
    for(ll &i : a) cin >> i;
    for(ll &i : b) cin >> i;
    ll ans = 0;
    for(ll i = 0; i <= 28; i++){
        ll cnt = 0;
        vector<ll> tmp;
        for(ll u : b) tmp.push_back(u % (1 << (i + 1)));
        sort(tmp.begin(), tmp.end());
        for(ll u : a){
            u %= (1 << (i + 1));
            cnt += num(tmp, (1 << i), (1 << (i + 1)), u);
            cnt += num(tmp, (1 << (i + 1)) + (1 << i), (1 << (i + 1)) + (1 << (i + 1)), u);
        }
        if(cnt & 1) ans += (1 << i);
    }
    cout << ans << endl;
    return 0;
}
