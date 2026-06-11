#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const int inf=1<<30;

int n,a,b,x,d[200009];
vector<int> e[200009];

int bfs(int s){
    rep(i,n+1)d[i]=inf;
    d[s]=0;
    queue<int> que;
    que.push(s);
    int now;
    while(!que.empty()){
        now=que.front();
        que.pop();
        rep(i,e[now].size()){
            if(d[e[now][i]]!=inf)continue;
            d[e[now][i]]=d[now]+1;
            que.push(e[now][i]);
        }
    }
    x=now;
    return d[now];
}

int main(){
    cin>>n;
    rep(i,n-1){
        cin>>a>>b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    bfs(1);
    cout<<(bfs(x)%3!=1?"First\n":"Second\n");
}