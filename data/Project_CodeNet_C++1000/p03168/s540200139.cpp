#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<time.h>
#include<climits>
#include<string>
#include<iomanip>

//#define IONAME "cttf"
//#define E_DEBUG
//#define TIMECOMP

int n;
long double dp[3000];

void marota(){
    std::cin>>n;
    dp[0]=1;
    for (int i=1;i<=n;i++){
        long double a;
        std::cin>>a;
        for (int j=i;j>=1;j--){
            dp[j]=dp[j-1]*a+dp[j]*(1-a);
        }
        dp[0]*=(1-a);
    }   
    long double ans=0L;
    for (int i=n;i>n/2;i--){
        ans+=dp[i];
    }
    std::cout<<std::setprecision(10)<<std::fixed<<ans;
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