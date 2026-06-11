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

int n,t,da[111000],db[111000],dc[111000];

void marota(){
    std::cin>>n;
    int a,b,c;
    for (int i=1;i<=n;i++){
        std::cin>>a>>b>>c;
        da[i]=std::max(db[i-1],dc[i-1])+a;
        db[i]=std::max(da[i-1],dc[i-1])+b;
        dc[i]=std::max(da[i-1],db[i-1])+c;
    }   
    std::cout<<std::max(std::max(da[n],db[n]),dc[n]);
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