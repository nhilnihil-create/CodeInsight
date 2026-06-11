#include<bits/stdc++.h> 
using namespace std;
using i64 = int_fast64_t;
#define rep(i, N) for(int i = 0; i < N; i++)

int main(){
    int H, W, D;
    cin >> H >> W >> D;

    vector<pair<int,int>> B(H*W+1);
    rep(h, H)rep(w, W) {
        int A; cin >> A;
        B[A] = {h+1, w+1};
    }

    int Q;
    cin >> Q;

    vector<i64> ans(H*W+1, 0);
    for(int i = 1; i <= D; i++){
        int k = i;
        while(k+D <= H*W) {
            ans[k+D] = ans[k] + abs(B[k].first - B[k+D].first) + abs(B[k].second - B[k+D].second);
            k += D; 
        }
    }
    
    rep(i, Q){
        int L, R;
        cin >> L >> R;
        cout << ans[R] - ans[L] << endl;
    }
}
