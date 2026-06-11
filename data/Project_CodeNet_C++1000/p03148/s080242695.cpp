#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n,k;
    cin >> n >> k;
    vector<vector<ll>> s(n);
    rep(i,n){
        ll t,d;
        cin >> t >> d;
        --t;
        s.at(t).push_back(d);
    }

    for(i = 0;i < n;++i){
        sort(all(s.at(i)), greater<ll>());
        if(s.at(i).empty()) s.at(i).push_back(-1e14);
    }
    sort(all(s), [&](vector<ll> a, vector<ll> b){
        return a.at(0) > b.at(0);
    });

    ll ans = 0;
    priority_queue<ll> pq;
    rep(i,k){
        ans += s.at(i).at(0);
        for(j = 1;j < s.at(i).size();++j) pq.push(s.at(i).at(j));
    }
    for(i = k;i < n;++i){
        for(j = 0;j < s.at(i).size();++j) pq.push(s.at(i).at(j));
    }

    ll tmp = ans;
    ans += k*k;
    for(ll x = k - 1;x >= 1;--x){
        ll v = s.at(x).at(0);
        ll w = pq.top();
        if(v < w){
            pq.pop();
            tmp += w;
            pq.push(v);
            tmp -= v;
        }else break;
        ans = max(ans, tmp + x*x);
    }
    cout << ans << endl;

    return 0;
}