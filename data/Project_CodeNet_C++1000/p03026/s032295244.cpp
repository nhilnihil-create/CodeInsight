#include <bits/stdc++.h>
using namespace std;

const int MAX_N=1e4+10;

int N,a,b,sum=0,now=0;
vector<vector<int>> G(MAX_N);
vector<int> c(MAX_N),ans(MAX_N);

void dfs(int v,int p){
    ans[v]=c[now++];
    for (int u:G[v]){
        if (u!=p) dfs(u,v);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i=0;i<N-1;++i){
        cin >> a >> b; --a,--b;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    for (int i=0;i<N;++i) cin >> c[i];
    sort(c.begin(),c.begin()+N);
    reverse(c.begin(),c.begin()+N);
    for (int i=1;i<N;++i) sum+=c[i];
    cout << sum << '\n';
    dfs(0,-1);
    for (int i=0;i<N;++i) cout << ans[i] << (i!=N-1?' ':'\n');
}