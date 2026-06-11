#include<iostream>
#include<vector>
//saw editional

int main(){
    int H,W;
    std::cin>>H>>W;
    std::vector<bool>map(H*W);
    for(int i=0;i<H;++i){
        for(int j=0;j<W;++j){
            char buf;
            std::cin>>buf;
            if(buf=='.'){
                map[i*W+j]=0;
            }else{
                map[i*W+j]=1;
            }
        }
    }
    std::vector<unsigned long long>dp(H*W,0);
    for(int i=0;i<H;++i){
        if(map[i*W+0]==1){
            break;
        }
        dp[i*W+0]=1;
    }
    for(int i=0;i<W;++i){
        if(map[0*W+i]==1){
            break;
        }
        dp[0*W+i]=1;
    }
    for(int i=1;i<H;++i){
        for(int j=1;j<W;++j){
            if(map[i*W+j]==0){
                dp[i*W+j]=(dp[(i-1)*W+j]+dp[i*W+(j-1)])%(1000000007);
            }
        }
    }
    std::cout<<dp[H*W-1]<<std::endl;
    return 0;
}