#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
typedef long long ll;
const ll MOD = 1e9+7;



int main(){
    int n, k; cin >> n >> k;
    vector<ll> x(n),y(n); rep(i,n) cin >> x[i] >> y[i];
    ll ans = 4000000000000000002;
    for(int x1 = 0; x1 < n; ++x1){ // 左端
        for(int x2 = 0; x2 < n; ++x2){ // 右端
            for(int y1 = 0; y1 < n; ++y1){ // 下端
                for(int y2 = 0; y2 < n; ++y2){ // 上端
                    int cnt = 0;
                    for(int i = 0; i < n; ++i){
                        if(x[i] >= x[x1] && x[i] <= x[x2] && y[i] >= y[y1] && y[i] <= y[y2]) cnt++;
                    }
                    if(cnt >= k) ans = min(ans, (y[y2]-y[y1])*(x[x2]-x[x1]));
                }
            }
        }
    }    
    cout << ans << endl;
}