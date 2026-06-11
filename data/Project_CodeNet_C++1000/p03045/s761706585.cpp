#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

ll opt=0;
vector<vector<ll>>g;
vector<ll>cnt;
vector<bool>ch;
void dfs(ll v,ll p=-1){
    for(auto u:g[v]){
        if(u==p)continue;
        if(ch[u])continue;
        ch[u]=true;
        dfs(u,v);
    }
}

int main(){
    ll ans=0;
    ll n,m;cin >>n>>m;
    g.resize(n);
    cnt.assign(n,0);
    ch.assign(n,false);
    for (int i = 0; i < m; ++i) {
        ll x,y,z;cin >>x>>y>>z;
        x--;y--;
        cnt[x]++;
        cnt[y]++;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 0; i < n; ++i) {
        if(ch[i])continue;
        ans++;
        dfs(i);
//        cout <<ans <<endl;
//        cout <<opt<<endl;
    }
    cout <<ans <<endl;
    return 0;
}

