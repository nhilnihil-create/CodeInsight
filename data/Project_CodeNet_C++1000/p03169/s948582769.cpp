#include<iostream>
#include<vector>
#include<iomanip>

// saw editional

class DP{
public:
    int N;
    std::vector<long double>dp;
    std::vector<bool>flags;
    DP(int N){
        this->N=N;
        dp=std::vector<long double>((N+1)*(N+1)*(N+1),1);
        dp.shrink_to_fit();
        flags=std::vector<bool>((N+1)*(N+1)*(N+1),0);
        flags.shrink_to_fit();
    }
    long double f(int c1,int c2,int c3){
        if(flags[c1*(N+1)*(N+1)+c2*(N+1)+c3]){
            return dp[c1*(N+1)*(N+1)+c2*(N+1)+c3];
        }
        long double ans=0;
        long double buf=1-(N-c1-c2-c3)/(double)N;
        if(0!=c1+c2+c3){
            ans+=1/buf;
        }
        if(c1>0){
            ans+=f(c1-1,c2,c3)*c1/(double)N/buf;
        }
        if(c2>0){
            ans+=f(c1+1,c2-1,c3)*c2/(double)N/buf;
        }
        if(c3>0){
            ans+=f(c1,c2+1,c3-1)*c3/(double)N/buf;
        }
        dp[c1*(N+1)*(N+1)+c2*(N+1)+c3]=ans;
        flags[c1*(N+1)*(N+1)+c2*(N+1)+c3]=1;
        return ans;
    }
};
int main(){
    int N;
    std::cin>>N;
    int cnt[3]={0,0,0};
    for(int i=0;i<N;++i){
        int buf;
        std::cin>>buf;
        cnt[buf-1]++;
    }
    DP dp(N);
    std::cout << std::fixed << std::setprecision(12);
    std::cout<<dp.f(cnt[0],cnt[1],cnt[2])<<std::endl;
}