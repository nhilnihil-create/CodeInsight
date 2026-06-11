#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;

vector<vector<int>> to(100005);
vector<int> checked(100005);

void dfs(int v){
    if(checked[v])return;
    checked[v]=1;
    for(int u:to[v]){
        dfs(u);
    }
    return;
}

int main() {
    int N,M;
    cin>>N>>M;
    rep(i,M){
        int x,y,z;
        cin>>x>>y>>z;
        x--;y--;
        to[x].pb(y);
        to[y].pb(x);
    }
    int count=0;
    rep(i,N){
        if(!checked[i]){
            count++;
            dfs(i);
        }
    }
    cout<<count<<endl;
}