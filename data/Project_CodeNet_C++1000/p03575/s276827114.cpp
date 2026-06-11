#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
const int MAX_N = 60;
int par[MAX_N];//親
int pank[MAX_N];//木の深さ

//n要素で初期化
void init(int n){
    for(int i=0;i<n;i++){
        par[i]=i;
        pank[i]=0;
    }
}

//木の根を求める
int find(int x){
    if(par[x]==x){
        return x;
    }else{
        return par[x]=find(par[x]);
    }
}

//xとyの属する集合を併合
void unite(int x,int y){
    x = find(x);
    y = find(y);
    if(x==y)return;
    if(pank[x]<pank[y]){
        par[x]=y;
    }else{
        par[y]=x;
        if(pank[x]==pank[y])pank[x]++;
    }
}

//xとyが同じ集合に属するか否か
bool same(int x,int y){
    return find(x)==find(y);
}
int main(void){
    int n,m;cin>>n>>m;
    vector<pair<int,int>> p(m);
    int res=0;
    rep(i,m){
        int a,b;cin>>a>>b;a--;b--;
        p[i]={a,b};
    }
    rep(i,m){
        init(n);
        bool ok=true;
        rep(j,m){
            if(i==j)continue;
            int a=p[j].first,b=p[j].second;
            unite(a,b);
        }
        rep(j,n)rep(k,n) if(!same(j,k))ok=false;
        if(!ok)res++;
    }
    cout<<res<<endl;
}