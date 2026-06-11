#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<time.h>
#include<climits>
#include<string>
//#define IONAME "cttf"
//#define E_DEBUG
//#define TIMECOMP

int n,t,a[111000],dp[111000];

void marota(){
    std::cin>>n;
    for (int i=1;i<=n;i++){
        std::cin>>a[i];
    }   
    a[0]=a[1];
    for (int i=2;i<=n;i++){
        dp[i]=std::min(dp[i-1]+std::abs(a[i]-a[i-1])
                      ,dp[i-2]+std::abs(a[i]-a[i-2])
                    );
    }
    std::cout<<dp[n];

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