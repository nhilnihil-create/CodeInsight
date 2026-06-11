#include <bits/stdc++.h>
using namespace std;

using P = pair<int,int>;
int main(void) {
    int H,W,D,a,Q;
    int l,r;
    cin >> H >> W >> D;

    // mod Dで累積和を取っておく
    map<int,P> mp;
    for(int i=1;i<=H;i++) {
        for(int j=1;j<=W;j++) {
            cin >> a;
            mp[a] = make_pair(i,j);
        }
    }

    vector<map<int,int>> sum(D);
    for(int i=0;i<D;i++) {
        sum[i][0] = 0;
    }
    vector<int> pos(D,0);
    for(int i=1;i<=(H*W);i++) {
        if(i+D > (H*W)) continue;
        sum[i%D][pos[i%D]+1] = sum[i%D][pos[i%D]] 
                     + abs(mp[i+D].first-mp[i].first)
                     + abs(mp[i+D].second-mp[i].second);
        pos[i%D]++;
    }

    cin >> Q;
    vector<int> ans(Q);
    for(int i=0;i<Q;i++) {
        cin >> l >> r;
        if(l == r) {
            ans[i] = 0;
        } else {
            if(l%D) {
            ans[i] = sum[r%D][r/D] - sum[l%D][l/D];
            } else {
            ans[i] = sum[r%D][r/D-1] - sum[l%D][l/D-1];
            }
        }
    }

    for(int i=0;i<Q;i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
