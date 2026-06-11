#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;
typedef pair<int,int> P;

int dist(P x, P y){
    return abs(x.first-y.first)+abs(x.second-y.second);
}

int main(){
    int H, W, D; cin >> H >> W >> D;
    vector<vector<int>> A(H, vector<int>(W));
    vector<P> coord(H*W);
    rep(i,H) rep(j,W){
        cin >> A[i][j]; A[i][j]--;
        coord[A[i][j]] = make_pair(i,j);
    }

    vector<int> sum_d(H*W, 0);

    for(int i = D; i<H*W; i++){
        int d = dist(coord[i], coord[i-D]);
        sum_d[i] = sum_d[i-D] + d;
    }

    int Q; cin >> Q;
    rep(query, Q){
        int L, R; cin >> L >> R; L--; R--;
        cout << sum_d[R] - sum_d[L] << endl;
    }    
}