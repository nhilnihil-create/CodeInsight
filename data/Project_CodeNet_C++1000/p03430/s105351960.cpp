#include<bits/stdc++.h>
using namespace std;


#define REP(i,n) for(int i=0;i<n;i++)


string st;

int mem[310][310][310];


int dfs(int l,int r,int x){
    if(r<l){
        return 0;
    }
    if(l==r){
        return 1;
    }
    if(mem[l][r][x]!=-1){
        return mem[l][r][x];
    }
    int res=max(dfs(l+1,r,x),dfs(l,r-1,x));
    if(st[l]==st[r]){
        res=max(res,dfs(l+1,r-1,x)+2);
    }
    if(x){
        res=max(res,dfs(l+1,r-1,x-1)+2);
    }
    return mem[l][r][x]=res;
}


int main(){
    cin>>st;
    int K;
    cin>>K;
    REP(i,300){
        REP(j,300){
            REP(k,301){
                mem[i][j][k]=-1;
            }
        }
    }
    cout<<dfs(0,st.size()-1,K)<<endl;
    return 0;
}