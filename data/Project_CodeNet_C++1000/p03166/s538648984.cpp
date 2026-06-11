#include<iostream>
#include<vector>
#include<algorithm>

void stupid(){
    int N,M;
    std::cin>>N>>M;
    std::vector<std::pair<int,int> > edges(M);
    for(auto& edge:edges){
        std::cin>>edge.first>>edge.second;
    }
    std::vector<int>dp(N*N,0);
    for(int i=1;i<N;++i){
        for(int j=0;j<M;++j){
            int start=edges[j].first,end=edges[j].second;
            if(start <= i && end <= i){
                dp[i*N+end]=std::max(dp[(i-1)*N+end],dp[(i-1)*N+start]+1);
            }
        }
    }
    auto maxitr=std::max_element(dp.end()-N-1,dp.end());
    std::cout<<*maxitr<<std::endl;
}
class dp{
    public:
    std::vector<int> dplog;
    std::vector<bool> flags;
    std::vector<std::pair<int,int> >edges;
    std::vector<std::vector<int> >degs;
    dp(int N,int M){
        dplog=std::vector<int>(N,0);
        flags=std::vector<bool>(N,0);
        edges=std::vector<std::pair<int,int> >(M);
        degs=std::vector<std::vector<int> >(N);
    }
    int f(int x){
        if(flags[x]){
            return dplog[x];
        }
        flags[x]=1;
        int ans=0;
        for(auto i:degs[x]){
            ans=std::max(ans,1+f(i));
        }
        dplog[x]=ans;
        return ans;
    }
};
void correct(){
    int N,M;
    std::cin>>N>>M;
    dp DP(N,M);
    for(auto& edge:DP.edges){
        std::cin>>edge.first>>edge.second;
        DP.degs[edge.second-1].push_back(edge.first-1);
    }
    int ans=0;
    for(int i=0;i<N;++i){
        int buf=DP.f(i);
        if(ans<buf)
            ans=buf;
    }
    std::cout<<ans<<std::endl;
}
int main(){
    correct();
}