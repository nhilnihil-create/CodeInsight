#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100001,INF=1<<30;
vector<int> S[MAX],cnt(MAX),par(MAX);

void init(int v){
    for(int i=0;i<v;i++){
        par[i]=i;
    }
}

void DFS(int u){
    stack<int> ST;
    ST.push(u);
    while(!ST.empty()){
        int a=ST.top();
        ST.pop();
        for(int i=0;i<S[a].size();i++){
            int b=S[a][i];
            if(cnt[b]>=2){
                cnt[b]--;
            }else{
                ST.push(b);
                par[b]=a;
            }
        }
    }
}

int main(){
    
    int N,M;cin>>N>>M;
    for(int i=0;i<N+M-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        S[a].push_back(b);
        cnt[b]++;
    }
    
    int s=0;
    
    for(int i=0;i<N;i++){
        if(cnt[i]==0) s=i;
    }
    
    init(N);
    
    DFS(s);
    
    for(int i=0;i<N;i++){
        if(s==i) cout<<0<<endl;
        else cout<<par[i]+1<<endl;
    }
}
