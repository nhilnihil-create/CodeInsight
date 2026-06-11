#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int N;
vector<vector<pair<int,int>>> tr;
vector<int> ans;

void DFS(int v,int p,int c){
    ans[v] = c;
    for(auto nv:tr[v]){
        if(nv.first == p) continue;
        if(nv.second%2==1){
            DFS(nv.first,v,(c+1)%2);
        }else{
            DFS(nv.first,v,c);
        }
    }
}

int main(){
    cin >> N;
    tr.assign(N,vector<pair<int,int>>());
    rep(i,N-1){
        int u,v,w;
        cin >> u >> v >> w;
        u--;v--;
        tr[u].push_back(make_pair(v,w));
        tr[v].push_back(make_pair(u,w));
    }
    ans.assign(N,0);
    DFS(0,-1,0);
    rep(i,N) cout << ans[i] << endl;
    return 0;
}