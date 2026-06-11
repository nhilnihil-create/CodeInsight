#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i,m){
        int x, y, z;
        cin >> x >> y >> z;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<bool> seen(n, false);
    int ans = 0;
    rep(i,n){
        if(seen[i]) continue;
        ans++;
        seen[i] = true;
        queue<int> que;
        que.push(i);
        while(!que.empty()){
            int v = que.front();
            que.pop();
            for(auto nv : g[v]){
                if(seen[nv]) continue;
                seen[nv] = true;
                que.push(nv);
            }
        }
    }
    cout << ans << endl;
}