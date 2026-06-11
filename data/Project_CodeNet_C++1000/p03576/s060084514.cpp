#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,i0,n) for(int i=i0;i<n;++i)

int main()
{
    int n,k;
    cin >> n >> k;
    vector<pair<ll,ll>> xy(n);
    rep(i,n) {
        cin >> xy[i].first >> xy[i].second;
    }
    sort(xy.begin(), xy.end());

    ll ans = INT64_MAX;
    for(int i=0;i<n-k+1;++i) {
        for(int j=i+k-1;j<n;++j) {
            vector<ll> y;
            for(int l=i;l<=j;++l) 
                y.push_back(xy[l].second);
            sort(y.begin(),y.end());

            ll dy = INT64_MAX;
            int l_max = y.size()-k+1;
            for(int l=0;l<l_max;++l)
                dy = min(dy, y[l+k-1]-y[l]);

            ans = min(ans, (xy[j].first-xy[i].first)*dy);
        }
    }

    cout << ans << endl;
    return 0;
}