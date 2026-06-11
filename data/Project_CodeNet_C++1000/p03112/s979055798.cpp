#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,i0,n) for(int i=i0;i<n;++i)

int main()
{
    int a,b,q;
    cin >> a >> b >> q;
    vector<ll> s(a), t(b), x(q);
    for(auto& si:s) cin >> si;
    for(auto& ti:t) cin >> ti;
    for(auto& xi:x) cin >> xi;

    const ll INF = 1e11;
    for(auto xi:x) {
        vector<vector<ll>> d(2,vector<ll>(2,INF));

        auto itr = lower_bound(s.begin(),s.end(),xi);
        if(itr != s.end()) d[0][1] = *itr - xi;
        if(itr != s.begin()) d[0][0] = xi - *(--itr);
        itr = lower_bound(t.begin(),t.end(),xi);
        if(itr != t.end()) d[1][1] = *itr - xi;
        if(itr != t.begin()) d[1][0] = xi - *(--itr);

        ll ans = min(max(d[0][0], d[1][0]), max(d[0][1], d[1][1]));
        if(d[0][0] != INF && d[1][1] != INF)
            ans = min(ans, 2*min(d[0][0],d[1][1]) + max(d[0][0],d[1][1]));
        if(d[0][1] != INF && d[1][0] != INF)
            ans = min(ans, 2*min(d[0][1],d[1][0]) + max(d[0][1],d[1][0]));

        cout << ans << endl;
    }
    
    return 0;
}