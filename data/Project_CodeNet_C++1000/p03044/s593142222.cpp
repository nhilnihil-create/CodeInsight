#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=(n);i++)
using ll=long long;
typedef pair<int,int> P;

int n,m;
vector<vector<P>> dat(101);
vector<int> col(10,-1);
vector<bool> check(10,false);

int main(){
    int n;
    cin>>n;
    col=vector<int>(n+10,-1);
    check=vector<bool>(n+10,false);
    dat=vector<vector<P>>(n+10);
    rep(i,n-1){
        int u,v,w;
        cin>>u>>v>>w;
        dat[u].push_back(P(v,w));
        dat[v].push_back(P(u,w));
    }
    queue<int> que;
    que.push(1);
    col[1]=0;
    while(que.size()){
        int q=que.front();que.pop();
        check[q]=true;
        for(auto p:dat[q]){
            if(col[p.first]!=-1) continue;
            if(p.second%2==0) col[p.first]=col[q];
            else col[p.first]=abs(1-col[q]);
            if(check[p.first]) continue;
            que.push(p.first);
        }
    }
    rep(i,n){
        cout<<col[i]<<endl;
    }
}