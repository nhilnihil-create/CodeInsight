#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(),(a).end()
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

int main(){
    int n,k; cin >> n >> k;
    vector<ll> xnum,ynum;
    vector<P> point;
    rep(i,n){
        ll x,y; cin >> x >> y;
        xnum.push_back(x);
        ynum.push_back(y);
        point.push_back(P(x,y));
    }
    sort(ALL(xnum));
    sort(ALL(ynum));
    ll ans = 4*1e18;
    for(int i = 0;i < n;++i){
        for(int j = i+1;j < n;++j){
            for(int p = 0;p < n;++p){
                for(int q = p+1;q < n;++q){
                    int cnt = 0;
                    rep(r,n){
                        ll x = point[r].first,y = point[r].second;
                        if(xnum[i] <= x && x <= xnum[j] && ynum[p] <= y && y <= ynum[q]) cnt++;
                    }
                    ll s = (xnum[j]-xnum[i])*(ynum[q]-ynum[p]);
                    if(cnt >= k && ans > s) ans = s;
                }
            }
        }
    }
    cout << ans << endl;
}