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

int n;
std::string s,t;
std::string dp[2][3123];
void marota(){
    std::cin>>s>>t;  
    s=" "+s;
    t=" "+t;
    int n=s.length(),m=t.length();
    int io=0;
    for (int i=1;i<n;i++){
        io=1-io;
        for (int j=1;j<m;j++){
            if (s[i]==t[j]){
                dp[io][j]=dp[1-io][j-1]+s[i];
            }
            else {
                if (dp[io][j-1].length()>dp[1-io][j].length()){
                    dp[io][j]=dp[io][j-1];
                }
                else dp[io][j]=dp[1-io][j];
            }
        }
    }
    std::cout<<dp[io][m-1];
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