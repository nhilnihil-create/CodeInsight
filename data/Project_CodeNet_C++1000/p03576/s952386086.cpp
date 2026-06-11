#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll =  long long ;
using P = pair<int,int> ;
using pll = pair<ll,ll>;
const ll INF = 1e18;
const int MOD = 1000000007;

int main(){
    int n,k;
    cin >> n >> k;
    vector<pll> xy(n);
    rep(i,n) cin >> xy[i].first >> xy[i].second;
    sort(xy.begin(),xy.end());
    ll ans = INF;
    bool update = false;
    for(int i=0;i<=n-k;i++){
        for(int j=i+k-1;j<n;j++){
            ll dx = xy[j].first - xy[i].first;
            vector<ll> y(j-i+1);
            for(int idx=i;idx<=j;idx++){
                y[idx-i] = xy[idx].second;
            }
            sort(y.begin(),y.end());
            int p = j-i+1;
            for(int idx=0;idx<=p-k;idx++){
                ll mn = y[idx];
                ll mx = y[idx+k-1];
                if(!update){
                    ans = (mx-mn)*dx;
                    update = true;
                }
                ans = min(ans,(mx-mn)*dx);
            }
        }
    }
    cout << ans << endl;
    return 0;
}