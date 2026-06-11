#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define int long long
using P = pair<int,int>;
vector<int> graph[110000];
int visited[110000];

void dfs(int now,int last = -1){
    for(auto next:graph[now]){
        if(next == last)continue;
        if(visited[next])continue;
        visited[next] = 1;
        dfs(next,now);
    }
}
signed main(){
    
    int n,m;cin >> n >> m;
    rep(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int ans = 0;
    rep(i,n){
        if(!visited[i]){
            dfs(i);
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}