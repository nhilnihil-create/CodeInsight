#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int dist (P x, P y) {
    return abs(x.first-y.first) + abs(x.second-y.second);
}
int main() {
    int h, w, d; cin >> h >> w >> d;
    vector<vector<int>> a(h+1, vector<int>(w+1));
    vector<P> id(h*w+1);
    rep(i, h) rep(j, w) {
        cin >> a[h][w];
        id[a[h][w]].first = i+1;
        id[a[h][w]].second = j+1;
    }
    vector<vector<int>> ruisekiwa(d+1);
    rep(i, d) {
        int x = i+1;
        ruisekiwa[i+1].push_back(0);
        while (x+d <= h * w) {
            ruisekiwa[i+1].push_back(dist(id[x+d],id[x])+ruisekiwa[i+1].back());
            x += d;
        }
    }
    /*rep(i, d) {
        rep(j, ruisekiwa[i].size()) {
            printf("%d ",ruisekiwa[i][j]);
        }puts("");
    }*/
    int q; cin >> q;
    ll ans = 0;
    rep(i, q) {
        int L, R; cin >> L >> R;
        int r = L % d;
        if(r==0) r=d;
        //printf("r:%d %d %d\n", r, (R-r)/d, (L-r)/d);
        cout << ruisekiwa[r][(R-r)/d] - ruisekiwa[r][(L-r)/d] << endl;
    }
}
