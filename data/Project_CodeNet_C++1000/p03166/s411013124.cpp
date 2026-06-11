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

int n,t,m;
std::vector<int> io,ii;
std::vector<std::vector<int> > vv;

void getData(){
    std::cin>>n>>m;
    vv.resize(n+1);
    io.assign(n+1,0);
    ii.assign(n+1,0);
    for (int i=1;i<=m;i++){
        int u,v;
        std::cin>>u>>v;
        vv[u].push_back(v);
    }
}

int dfs(int u){
    int ans=0;
    if (ii[u]!=0) return ii[u];
    for (auto v:vv[u]){
        ans=std::max(ans,dfs(v)+1);
    }
    ii[u]=ans;
    return ans;
}

void marota(){
    getData();
    int ans=0;
    for (int i=1;i<=n;i++){
        if (ii[i]==0){
            ans=std::max(ans,dfs(i));
        }
    }
    std::cout<<ans;
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