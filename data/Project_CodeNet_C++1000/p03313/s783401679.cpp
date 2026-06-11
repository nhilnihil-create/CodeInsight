#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int A[1<<20];
int dp1[1<<20][20] = {},dp2[1<<20][20] = {};

int main(){
    cin >> N;
    for(int i=0;i<(1<<N);i++){
        cin >> A[i];
        dp1[i][0] = A[i];
    }
    for(int j=0;j<N;j++){
        for(int i=0;i<(1<<N);i++){
            priority_queue<int> Q;
            if(i&(1<<j)){
                Q.push(dp1[i][j+1]);
                Q.push(dp2[i][j+1]);
                Q.push(dp1[i][j]);
                Q.push(dp2[i][j]);
                Q.push(dp1[i&~(1<<j)][j]);
                Q.push(dp2[i&~(1<<j)][j]);
            }else{
                Q.push(dp1[i][j+1]);
                Q.push(dp2[i][j+1]);
                Q.push(dp1[i][j]);
                Q.push(dp2[i][j]);
            }
            dp1[i][j+1] = Q.top();
            Q.pop();
            dp2[i][j+1] = Q.top();
        }
    }
    int ans = 0;
    for(int i=1;i<(1<<N);i++){
        ans = max(ans,dp1[i][N]+dp2[i][N]);
        cout << ans << endl;
    }
}