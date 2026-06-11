#include <bits/stdc++.h>
using namespace std;

const int mx =  302;
int N;

double dp[mx][mx][mx];

double getdp(int xx,int yy, int zz) {
    if(xx < 0 || yy < 0 || zz < 0)
        return 0.0;
    if(dp[xx][yy][zz] >= 0.0)
        return dp[xx][yy][zz];

    dp[xx][yy][zz] = 0.0;
    double mul_ = 1.0, add_ = 0.0;
    // already eaten
    if(xx + yy + zz < N){
        mul_ = 1.0 * N / (xx + yy + zz);
        add_ = 1.0 * (N - xx -yy - zz) / (xx + yy + zz);
        dp[xx][yy][zz] += add_;
    }

    dp[xx][yy][zz] += mul_* (getdp(xx-1,yy,zz) + 1) * xx / N;
    dp[xx][yy][zz] += mul_* (getdp(xx+1,yy-1,zz) + 1) * yy / N;
    dp[xx][yy][zz] += mul_* (getdp(xx, yy+1, zz-1) + 1) * zz / N;
//    printf("%d %d %d : %lf\n", xx, yy, zz, dp[xx][yy][zz]);
    return dp[xx][yy][zz];
}

int main(){
    scanf("%d",&N);
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;

    for(int i = 0 ;i < N; ++i){
        int tmp;scanf("%d", &tmp);
        switch (tmp) {
            case 1: cnt1 ++;break;
            case 2: cnt2 ++;break;
            case 3: cnt3 ++;break;
            default: break;
        }
    }
    // init dp, must N;
    for(int i = 0 ;i <= N; ++i){
        for(int j = 0 ;j <= N ; ++j){
            for(int k = 0 ; k <= N ; ++k){

//                printf("%d %d %d",i,j,k);
//                puts("OK");

                dp[i][j][k] = -1.0;
            }
        }
    }
    dp[0][0][0] = 0.0;

    printf("%.10lf\n",getdp(cnt1,cnt2,cnt3));

    return 0;
}