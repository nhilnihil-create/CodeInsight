#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100001,INF=1<<30;
vector<int> S[MAX],dis(MAX);
ll N;

void BFS(){
    queue<int> Q;
    dis[0]=0;
    Q.push(0);
    while(!Q.empty()){
        int a=Q.front();
        Q.pop();
        for(int i=0;i<S[a].size();i++){
            int b=S[a][i];
            if(dis[b]!=-1) continue;
            dis[b]=dis[a]+1;
            Q.push(b);
        }
    }
}


int main(){
    int M;cin>>N>>M;
    vector<pair<int,int>> T(M);
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        S[a].push_back(b);
        S[b].push_back(a);
        T[i]=make_pair(a,b);
    }
    for(int i=0;i<N;i++){
        dis[i]=-1;
    }

    BFS();

    bool flag=true;

    for(int i=0;i<M;i++){
        int a=T[i].first;
        int b=T[i].second;
        if((dis[a]-dis[b])%2==0) flag=false;
    }

    if(flag){
        ll red=0,blue=0;
        for(int i=0;i<N;i++){
            if(dis[i]%2) red++;
            else blue++;
        }
        cout<<red*blue-M<<endl;
    }else{
        cout<<N*(N-1)/2-M<<endl;
    }


}