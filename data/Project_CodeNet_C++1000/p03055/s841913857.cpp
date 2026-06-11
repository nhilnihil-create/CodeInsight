/// You just can't beat the person who never gives up
/// ICPC next year

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+5 ;

int n ,u ,v ;
vector<int> adj[N] ;
int leave ,diamater ;
void dfs(int p,int gp,int d){
    if(d>diamater) diamater = d ,leave = p ;
    for(int ch:adj[p]) if(ch!=gp) dfs(ch,p,d+1);
}

int mem[N][2] ;
int solve(int d,int cur){
    if(d==0) return 1-cur ;
    if(d==1) return cur ;
    if(d==2) return 1-cur ;
    int&ret=mem[d][cur];
    if(~ret) return ret;
    int a = solve(d-1,1-cur);
    int b = solve(d-2,1-cur);
    if(a==cur) return ret = cur ;
    if(b==cur) return ret = cur ;
    return ret = 1-cur ;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;++i){
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,1,1);
    dfs(leave,leave,1);
    memset(mem,-1,sizeof mem);
    int x = solve(diamater,0) ;
    puts(x==0?"First":"Second");
    return 0;
}
