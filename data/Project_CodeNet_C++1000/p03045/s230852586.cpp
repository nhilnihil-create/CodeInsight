#include<bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using pint = pair<int,int>;
using pll = pair<ll,ll>;
using Graph = vector<vector<int>>;

int main(){
    int N,M,res = 0;
    cin>>N>>M;
    Graph G(N);//0-ind
    vector<int> X(M),Y(M),Z(M);
    rep(i,M){
        cin>>X[i]>>Y[i]>>Z[i];
        G[X[i]-1].push_back(Y[i]-1);
        G[Y[i]-1].push_back(X[i]-1);
    }
    vector<int> dist(N,-1);
    rep(i,N){
        if(dist[i]!=-1)continue;
        res++;
        queue<int> Q;
        Q.push(i);
        dist[i] = 0;
        while(!Q.empty()){
            int v = Q.front(); Q.pop();
            for(auto nv: G[v]){
                if(dist[nv]!=-1)continue;
                dist[nv] = dist[v] + 1;
                Q.push(nv);
            }
        }
    }
    cout<<res<<endl;
}
