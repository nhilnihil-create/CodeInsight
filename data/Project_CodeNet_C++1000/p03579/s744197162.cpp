#include <bits/stdc++.h>
#include <climits>
using namespace std;


vector<vector<int>> G;
int color[100050];
bool dfs(int u,int c){
    color[u] = c;
    for(int i = 0; i < G[u].size();i++){
        int v = G[u][i];
        if(color[v]==c)return false;
        if(color[v]==0 && !dfs(v,-c))return false;
    }
    return true;
}


int main(void){
    long long N,M;
    cin >> N >> M;
    int A,E;

    G.assign(N,vector<int>());
    for(int i = 0; i < M;i++){
        cin >> A >> E;
        A--;
        E--;
        G[A].push_back(E);
        G[E].push_back(A);
    }
    long long B = 0, W = 0;

    if(dfs(0,1)){
        for(int i = 0; i < N;i++){
            if(color[i] == 1){
                B++;
            }else if(color[i] == -1){
                W++;
            }
        }
        cout << B*W-M<<endl;   
    }else{
        cout << N*(N-1)/2 - M <<endl;
    }
        
        
        
        
    
    
}