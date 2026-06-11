#include <iostream>
#include <vector>

int root(int x,std::vector<int>& par);
void Unite(int x,int y,std::vector<int>& par,std::vector<int>& rank);
bool isSameSet(int x,int y,std::vector<int> par);
int max(int a,int b);
int main() {
    int M,N;
    std::cin >> N >> M;
    std::vector<int> P(N+1);
    std::vector<int> par(N+1);
    std::vector<int> rank(N+1,1);
    for(int i=1;i<N+1;i++){
        par[i] = i;
    }
    for(int i=1;i<N+1;i++){
        std::cin >> P[i];
    }
    for(int i=0;i<M;i++){
        int x,y;
        std::cin >> x >> y;
        Unite(x,y,par,rank);
    }
    int ans=0;
    for(int i=1;i<N+1;i++){
        if(isSameSet(P[i],i,par)){
            ans++;
        }
    }
    std::cout << ans;
    return 0;
}

int root(int x,std::vector<int>& par){
    if(par[x] == x)
        return x;
    else{
        int rx = root(par[x],par);
        par[x] = rx;
        return rx;
    }

}

void Unite(int x,int y,std::vector<int>& par,std::vector<int>& rank){
    int rx = root(x,par);
    int ry = root(y,par);
    if(rx == ry)
        return;
    if(rank[rx] <= rank[ry]) {
        par[rx] = ry;
        rank[ry] = max(rank[rx]+1,rank[ry]);
    }
    else{
        par[ry] = rx;
        rank[rx] = max(rank[ry]+1,rank[rx]);
    }
    return;
}

bool isSameSet(int x,int y,std::vector<int> par){
    int rx = root(x,par);
    int ry = root(y,par);
    return rx == ry;
}

int max(int a,int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}