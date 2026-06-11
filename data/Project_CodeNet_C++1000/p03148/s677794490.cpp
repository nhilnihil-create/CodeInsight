#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,i0,n) for(int i=i0;i<n;++i)

int main()
{
    int n,k;
    cin >> n >> k;
    vector<pair<ll,int>> dt(n);
    rep(i,n) cin >> dt[i].second >> dt[i].first;
    sort(dt.begin(), dt.end(), greater<pair<ll,int>>());

    queue<ll> q0;
    queue<ll> q1;
    unordered_map<int, int> mp;

    ll tmp = 0;
    rep(i,k) {
        ll di = dt[i].first;
        ll ti = dt[i].second;
        tmp += di;
        if(mp.count(ti) == 0) { mp[ti] = 1; }
        else { ++mp[ti]; }
    }    
    ll x = mp.size();
    tmp += x*x;
    ll ans = tmp;
    
    for(int i=k-1;i>=0;--i) {
        ll di = dt[i].first;
        ll ti = dt[i].second;
        if(mp[ti] > 1) {
            q0.push(di);
            --mp[ti];
        }
    }

    rep2(i,k,n) {
        ll di = dt[i].first;
        ll ti = dt[i].second;
        if(mp.count(ti) == 0) { 
            q1.push(di);
            mp[ti] = 1;
        }
    }

    while(!q0.empty() && !q1.empty()) {
        tmp = tmp - q0.front() + q1.front() + 2*x + 1;
        ans = max(ans, tmp);
        q0.pop(); q1.pop();
        ++x;
    }
    
    cout << ans << endl;
    return 0;
}