#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200003,INF=1<<30;
vector<int> S[MAX],dis(MAX);
int N;

void BFS(int u){
    
    for(int i=0;i<N;i++){
        dis[i]=INF;
    }
    
    queue<int> Q;
    
    dis[u]=0;
    Q.push(u);
    
    while(!Q.empty()){
        int a=Q.front();
        Q.pop();
        for(int i=0;i<S[a].size();i++){
            int b=S[a][i];
            if(dis[b]!=INF) continue;
            dis[b]=dis[a]+1;
            Q.push(b);
        }
    }
}

int main(){
    
    cin>>N;
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        S[a].push_back(b);
        S[b].push_back(a);
    }
    
    BFS(0);
    int maxi=0,s=0;
    
    for(int i=0;i<N;i++){
        if(dis[i]>maxi){
            maxi=dis[i];
            s=i;
        }
    }
    
    BFS(s);
    
    maxi=0;
    
    for(int i=0;i<N;i++){
        if(dis[i]>maxi){
            maxi=dis[i];
        }
    }
    
    if(maxi%3==1) cout<<"Second"<<endl;
    else cout<<"First"<<endl;
}


