#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 5001001001001001001;

ll N, K, ans=INF, tmp=0;
vector<ll> Xs, Ys;
vector<pair<ll,ll>> XY;

signed main(){
    cin >> N >> K;
    for(int i=0;i<N;i++) {
        ll x, y;
        cin >> x >> y;
        XY.push_back(make_pair(x,y));
        Xs.push_back(x);
        Ys.push_back(y);
    }
    sort(Xs.begin(),Xs.end());
    sort(Ys.begin(),Ys.end());
    for(int i1=0;i1<N;i1++) {
        for(int i2=i1+1;i2<N;i2++) {                    
            for(int j1=0;j1<N;j1++) {
                for(int j2=j1+1;j2<N;j2++) {
                    tmp = 0;
                    for(int k=0;k<N;k++) {
                        if(XY[k].first>=Xs[i1]&&XY[k].first<=Xs[i2]&&XY[k].second>=Ys[j1]&&XY[k].second<=Ys[j2]) {
                            tmp++;
                        }
                    }
                    if(tmp>=K) {
                        ans = min(ans,(Xs[i2]-Xs[i1])*(Ys[j2]-Ys[j1]));
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}