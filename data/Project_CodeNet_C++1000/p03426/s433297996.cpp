#include <bits/stdc++.h>

using namespace std;

int main(){
    int H,W,D,Q;
    cin >> H >> W >> D;
    vector<vector<int>> A(H*W+1,vector<int>(2));
    int ans[H*W+1];
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            int a;
            cin >> a;
            A[a][0] = i;
            A[a][1] = j;
        }
    }

    for(int i=1;i<=D;i++){
        int now = i;
        ans[now] = 0;
        now += D;
        while(now<=H*W){
            ans[now] = ans[now-D] + abs(A[now-D][0]-A[now][0]) + abs(A[now-D][1]-A[now][1]);
            now += D;
        }
    }

    cin >> Q;

    for(int i=0;i<Q;i++){
        int L,R;
        cin >> L >> R;
        cout << ans[R]-ans[L] << endl;
    }
}