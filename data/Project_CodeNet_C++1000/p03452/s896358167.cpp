#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
vector<P> graph[100010];
vector<ll> dist;
bool dfs(int x, int d){
    dist[x] = d;
    for(auto p:graph[x]){
        if(dist[p.first] != INF){
            if(dist[p.first] != d + p.second){
                return true;
            }else continue;
        }
        if(dfs(p.first, d + p.second))return true;
    }
    return false;
}
main(){
    int N,M;
    cin >> N >> M;
    rep(i,0,M){
        int l,r,d;
        cin >> l >> r >> d;
        l--,r--;
        graph[l].emplace_back(r,d);
        graph[r].emplace_back(l,-d);
    }
    dist.resize(N, INF);
    rep(i,0,N){
        if(dist[i] != INF)continue;
        if(dfs(i, 0)){
            //cout << i << endl;
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}