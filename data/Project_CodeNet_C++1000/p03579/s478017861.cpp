#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
#define MAXN 100001
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
typedef vector<vector<ll>> Graph;
ll N,M;
ll color[MAXN];
bool col(const Graph &G,int x,int c = 1){
    color[x] = c;
    for(auto nxt:G[x]){
        if(color[nxt]==c){
            return false;
        }
        if(color[nxt]==-1&&!col(G,nxt,1-c)){
            return false;
        }
    }
    return true;
}


int main(){
    cin >> N >>M;
    Graph G(N+1);
    rep(i,N)color[i] = -1;
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    ll B = 0,W = 0;
    if(col(G,0)){
        rep(i,N){
            if(color[i]==0)B++;
            if(color[i]==1)W++;
        }
        cout << B*W - M << endl;;
    }else{
        cout << ((N*(N-1))/2)-M << endl;
    }

    return 0;

}