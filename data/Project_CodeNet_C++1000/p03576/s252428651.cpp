#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n,k;
    cin>>n>>k;
    vector<pair<ll,ll>> d;
    set<ll> xs,ys;
    for(int i = 0; i < n; ++i){
        ll a,b;
        cin>>a>>b;
        d.emplace_back(a,b);
        xs.insert(a);
        ys.insert(b);
    }
    auto itxl=xs.begin();
    ll ans=5000000000000000000LL;
    while(itxl!=xs.end()) {
        auto itxr=itxl;
        ++itxr;
        while(itxr!=xs.end()) {
            auto ityl=ys.begin();
            while(ityl!=ys.end()) {
                auto ityr=ityl;
                ++ityr;
                while(ityr!=ys.end()) {
                    ll xl=*itxl,xr=*itxr,yl=*ityl,yr=*ityr;
                    int cnt=0;
                    for(int i = 0; i < n; ++i){
                        if(xl<=d[i].first&&d[i].first<=xr&&yl<=d[i].second&&d[i].second<=yr)++cnt;
                    }
                    if(cnt>=k) {
                        ans=min(ans,(xr-xl)*(yr-yl));
                        //break;
                    }
                    ++ityr;
                }
                ++ityl;
            }
            ++itxr;
        }
        ++itxl;
    }
    cout<<ans<<endl;
    return 0;
}