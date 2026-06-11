#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector

int main(){
    ll n, k;
    cin >> n >> k;
    ve<P> dt(n);
    ve<ll> fl(n,0);
    rep(i,n) {
        cin >> dt[i].second >> dt[i].first;
        dt[i].second--;
    }
    sort(dt.rbegin(), dt.rend());
    ll ans = 0;
    ll cnt = 0;
    priority_queue<P> kouho;
    rep(i,k){
        ans += dt[i].first;
        if(fl[dt[i].second] == 0) cnt++;
        else kouho.push(P(-dt[i].first,dt[i].second));
        fl[dt[i].second] += 1;
    }
    ans += cnt*cnt;
    ve<ll> x;
    x.push_back(ans);
    ll i = k;
    while(i<n && !kouho.empty()){
        if(fl[dt[i].second] != 0){
            i++;
            continue;
        }
        ans -= cnt*cnt;
        ans += kouho.top().first;
        kouho.pop();
        cnt++;
        ans += cnt*cnt;
        ans += dt[i].first;
        fl[dt[i].second] = 1;
        x.push_back(ans);
        i++;
    }
    sort(x.rbegin(), x.rend());
    cout << x[0] << endl;
    return 0;
}
