#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<ll, ll>;

int main(){
    int n, k; cin >> n >> k;
    vector<P> pos;
    vector<int> xarr, yarr;
    rep(i,n){
        int x, y; cin >> x >> y;
        pos.push_back(P(x,y));
        xarr.push_back(x);
        yarr.push_back(y);
    }
    sort(ALL(xarr));
    sort(ALL(yarr));
    ll ans =  1LL * (xarr[n-1] - xarr[0]) * (yarr[n-1] - yarr[0]);
    for(int xi = 0; xi < n; xi++){
        for(int xj = xi+1; xj < n; xj++){
            for(int yi = 0; yi < n; yi++){
                for(int yj = yi+1; yj < n; yj++){
                    int cnt = 0;
                    ll lx = xarr[xi], rx = xarr[xj];
                    ll by = yarr[yi], uy = yarr[yj];
                    rep(i,n){
                        if(lx <= pos[i].first && pos[i].first <= rx && by <= pos[i].second && pos[i].second <= uy) cnt++;
                    }
                    if(cnt >= k) ans = min(ans, 1LL * (rx-lx)*(uy-by));
                }
            }
        }
    }
    cout << ans << endl;
}