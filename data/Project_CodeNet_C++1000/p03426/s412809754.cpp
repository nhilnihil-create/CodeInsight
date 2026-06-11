#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < b; i++)
typedef pair<int,int> P;
typedef long long ll;

int main(){
    int H, W, D; cin >> H >> W >> D;
    vector<P> mp(H * W);
    rep(i, 0, H) rep(j, 0, W){
        int p; cin >> p; p--;
        mp[p] = {i,j};
    }

    int Q; cin >> Q;
    vector<int> L(Q), R(Q);
    rep(i, 0, Q) cin >> L[i] >> R[i], L[i]--, R[i]--;

    vector<ll> sum(H * W);
    rep(i, 0, H * W){
        if(i < D) sum[i] = 0;
        else{
            int dx = abs(mp[i].first - mp[i-D].first);
            int dy = abs(mp[i].second - mp[i-D].second);
            sum[i] = sum[i - D] + dx + dy;
        }
    }
/*     rep(i, 0, H * W){
        cout << i << " " << sum[i] << endl;
    } */
    rep(i, 0, Q){
        cout << sum[R[i]] - sum[L[i]] << endl;
    }
}
