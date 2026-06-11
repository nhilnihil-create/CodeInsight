#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
int N,M;
vector<P> graph[200010];
vector<int> dist;
bool dfs(int now, int d){
    //cout << " " << now << endl;
    dist[now] = d;
    for(auto p:graph[now]){
        if(dist[p.first] != INF){
            if(dist[p.first] != d + p.second)return true;
            continue;
        }
        if(dfs(p.first, d + p.second))return true;
    }
    return false;
}
main(){ 
    cin >> N >> M;
    int num = 0;
    rep(i,0,M){
        int a,b,c;
        cin >> a >> b >> c;
        a--,b--;
        graph[a].emplace_back(b,c);
        graph[b].emplace_back(a,-c);
        num = a;
    }
    dist = vector<int>(N,INF);
    rep(i,0,N){
        int cost = dist[i];
        if(cost == INF)cost = 0;
        if(dist[i] == INF && dfs(i, 0) ){
            cout << "No" << endl;
            //cout << i << endl;
            return 0;
        }
        //for(auto i:dist)cout << i << " ";cout << endl;
    }
    cout << "Yes" << endl;
}