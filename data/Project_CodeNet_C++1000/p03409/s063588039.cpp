#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct edge {int to,w,p;};
int n,m,k,used[202],a,b,c,cnt,A[202],B[202];
vector<edge> v[202];
int dfs(int s,int t,int r){
    if(s==t)return r;
    used[s]=1;
    for(int i=0;i<v[s].size();i++){
        edge &u=v[s][i];
        if(used[u.to]==0&&u.w>0){
            int F=dfs(u.to,t,min(r,u.w));
            if(F>0){
                u.w-=F;v[u.to][u.p].w+=F;return F;
            }
        }
    }
    return 0;
}
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i]>>B[i];
        a=200,b=i;
        edge p={b,1,(int)v[b].size()};v[a].push_back(p);
        edge q={a,0,(int)v[a].size()-1};v[b].push_back(q);
    }
    for(int i=100;i<100+n;i++){
        cin>>A[i]>>B[i];
        a=i,b=201;
        edge p={b,1,(int)v[b].size()};v[a].push_back(p);
        edge q={a,0,(int)v[a].size()-1};v[b].push_back(q);
    }
    for(int i=0;i<n;i++){
        for(int j=100;j<100+n;j++){
            if(A[i]<A[j]&&B[i]<B[j]){
                a=i,b=j;
                edge p={b,1,(int)v[b].size()};v[a].push_back(p);
                edge q={a,0,(int)v[a].size()-1};v[b].push_back(q);
            }
        }
    }
    int res=0;
    while(1){
        for(int i=0;i<202;i++)used[i]=0;
        int P=dfs(200,201,1e9);
        if(P==0)break;
        res++;
    }
    cout<<res<<endl;
}
