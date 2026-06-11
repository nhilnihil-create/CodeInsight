#include<bits/stdc++.h>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (n); i++)

 
int main(){
    int H,W,D;
    cin >> H >> W >> D;
    int A[H][W];
    int X[H * W],Y[H * W];

    rep(i,H){
        rep(j,W){
            cin >> A[i][j];
            Y[A[i][j] - 1] = i;
            X[A[i][j] - 1] = j;
        }
    }

    int Z[H * W];
    for(int i=0;i<D;i++){
        Z[i] = 0;
        for(int j=i+D;j<W*H;j+=D){
            Z[j] = Z[j-D] + abs(X[j] - X[j-D]) + abs(Y[j] - Y[j-D]);
        }
    }
    int Q;
    cin >> Q;
    rep(i,Q){
        int L,R;
        cin >> L >> R;
        cout << Z[R-1] - Z[L-1] << endl;
    }
    return 0;
}