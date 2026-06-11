#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200003;
const ll INF=1LL<<60;
vector<int> G[MAX];
int cnta[MAX],cntb[MAX],out[MAX];
string S;

void DFS(int u,int p){
    for(int to:G[u]){
        if(out[to]||to==p) continue;
        if(S[u]=='A'){
            cnta[to]--;
        }else{
            cntb[to]--;
        }
        
        if(cnta[to]&&cntb[to]) continue;
        
        out[to]=1;
        DFS(to,u);
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    cin>>S;
    for(int i=0;i<M;i++){
        int u,v;cin>>u>>v;
        u--;v--;
        G[u].push_back(v);
        G[v].push_back(u);
        
        if(S[u]=='A'){
            cnta[v]++;
        }else{
            cntb[v]++;
        }
        
        if(S[v]=='A'){
            cnta[u]++;
        }else{
            cntb[u]++;
        }
    }
    
    for(int i=0;i<N;i++){
        if(cnta[i]==0||cntb[i]==0){
            if(out[i]==0){
                out[i]=1;
                DFS(i,-1);
            }
        }
    }
    
    bool ok=false;
    
    for(int i=0;i<N;i++){
        if(cnta[i]&&cntb[i]) ok=true;
    }
    
    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

