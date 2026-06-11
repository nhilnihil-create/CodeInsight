#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;





int main(){
    int N;
    cin >> N;
    
    //グラフの構造をもつ
    vector<vector<int>> to(N),cost(N);
    rep(i,N-1){
        int a,b,w;
        cin >> a >> b >> w;
        a--;
        b--;
        to[a].push_back(b); cost[a].push_back(w);
        to[b].push_back(a); cost[b].push_back(w);
    }
    
    //根から探索
    vector<int> ans(N,-1);
    queue<int> q;
    ans[0]=0;
    q.push(0);
    
    while(!q.empty()){
        int v = q.front();
        q.pop();
        rep(i,to[v].size()){
            int u= to[v][i];
            int w= cost[v][i];
            if(ans[u] != -1) continue;
            ans[u] = (ans[v] + w) %2;
            q.push(u);
        }
    }
    
    for(int i:ans){
        cout << i << endl;
    }
}
