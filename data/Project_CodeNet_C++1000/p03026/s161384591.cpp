#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod = int(1e9)+7;
using V = vector<ll>;
using P = pair<ll,ll>;

vector<vector<ll>>g;
vector<ll>d;
queue<ll>que;
vector<ll>c;
vector<bool>memo;
void bfs(ll v,ll i){
    if(memo[v]==false)return;
    memo[v]=false;
    d[v]=c[i];
    for(auto u:g[v]){
        que.push(u);
    }
    while(!que.empty()){
        ll nx=que.front();
        que.pop();
        bfs(nx,i+1);
    }
}

int main(){
    ll n;cin >>n;
    g.assign(n,V());
    d.resize(n);
    c.resize(n);
    memo.assign(n,true);
    for (int i = 0; i < n-1; ++i) {
        ll a,b;cin >>a>>b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        cin >>c[i];
    }
    sort(all(c));
    reverse(all(c));
    ll ans=0;
    for (int j = 0; j < n; ++j) {
        ans+=(j!=0)?c[j]:0;
    }
    bfs(0,0);
    cout <<ans<<endl;
    for (int k = 0; k < n; ++k) {
        cout << d[k]<<" ";
    }
    cout <<endl;
    return 0;
}