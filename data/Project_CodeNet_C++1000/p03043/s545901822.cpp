#include<stdio.h>
#include<iostream>
#include<string>
#include<memory>
#include<cmath>
#include<algorithm>
#include<vector>
int main(){
    int N,K;

    std::cin>>N>>K;
    double ans=0;
    double cal=0;
    
    for(int i=1;i<=N;i++){
        int ed=0;
        int score=i;
        double coin=1.0;
        while(score<K){
            score*=2;
            coin/=2;
        }
        cal+=coin;
    }
    ans=cal/N;

    //std::cout<<ans<<std::endl;
    printf("%.12f\n",ans);
    
    return 0;
}

