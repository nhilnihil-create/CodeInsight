#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<time.h>
#include<climits>
#include<string>
#include<queue>

//#define IONAME "cttf"
//#define E_DEBUG
//#define TIMECOMP

const int md=1e9+7;

int n,m;
char w;
long long dp[1100][1100];

void marota(){
    std::cin>>n>>m;
    dp[1][1]=1;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            std::cin>>w;
            if (w=='.' && (i!=1 || j!=1) ){
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%md;
            }
        }
    }   
    std::cout<<dp[n][m]%md;
}

int main(){
    #ifdef TIMECOMP
    clock_t tStart = clock();
    #endif
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    #if defined(IONAME)
    freopen(IONAME".INP","r",stdin);
    freopen(IONAME".OUT","w",stdout);
    #endif
    marota();
    #ifdef TIMECOMP
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    #endif
    return 0;
}