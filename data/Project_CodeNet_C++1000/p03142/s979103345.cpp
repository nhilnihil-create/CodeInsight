#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1e9+7;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

int main(){
    int N,M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    vector<int> cnt(N);
    rep(i,N-1+M){
        int a,b;
        cin >> a >> b;
        --a,--b;
        G[a].push_back(b);
        ++cnt[b];
    }
    int root;
    rep(i,N) if (cnt[i]==0) root=i;
    vector<int> par(N,-1);
    queue<int> que;
    que.push(root);
    while(!que.empty()){
        int v=que.front();
        que.pop();
        for (auto nv:G[v]){
            --cnt[nv];
            if (cnt[nv]>0) continue;
            que.push(nv);
            par[nv]=v;
        }
    }
    rep(i,N) cout << par[i]+1 << endl;
}
