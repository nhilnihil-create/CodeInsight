#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
using namespace std;
using ll = long long;

vector<int> to[100005];
vector<bool> visited;
void dfs(int i){
    visited[i] = true;
    for(int k : to[i]){
        if(visited[k])continue;
        dfs(k);
    }
}

int main()
{
    // input
    int n,m;
    cin >> n >> m;
    vector<int> hint(n);
    rep(i,m){
        int x,y,z;
        cin >> x >> y >> z;
        x--;y--;
        to[x].emplace_back(y);
        to[y].emplace_back(x);
    }

    // solve
    visited.resize(n);
    int ans=0;
    rep(i,n){
        if(visited[i])continue;
        dfs(i);
        ans++;
    }


    // output
    cout << ans << endl;

    return 0;
}