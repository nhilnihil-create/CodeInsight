#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<int> ans;
vector<P> to[100005];

void dfs(int i, int j=-1){
    for(P u : to[i]){
        if(u.first == j) continue;
        if(u.second % 2 == 0){
            ans[u.first] = ans[i];
        }else{
            ans[u.first] = -ans[i];
        }
        dfs(u.first, i);
    }
}


int main()
{
    // input
    int n;
    cin >> n;
    rep(i,n-1){
        int u,v,w;
        cin >> u >> v >> w;
        u--;v--;
        to[u].emplace_back(make_pair(v,w));
        to[v].emplace_back(make_pair(u,w));
    }

    // solve
    ans.resize(n);
    ans[0] = 1;
    dfs(0);

    // ouput
    rep(i,n){
        if(ans[i]==-1) cout << '0' << endl;
        else if(ans[i]==1) cout << '1' << endl;
    }

    return 0;
}
