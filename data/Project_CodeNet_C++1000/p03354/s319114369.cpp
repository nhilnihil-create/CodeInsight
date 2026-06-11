#include <bits/stdc++.h>
#define ll long long
#define pq priority_queue
using namespace std;
const ll INF=(ll)1e9;
const ll MOD=(ll)1e9+7;
const ll MAX=510000;
vector<int> dx={1,0,-1,0},dy={0,1,0,-1};
template<class T> inline bool chmax(T& a, T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a>b) { a=b; return 1; } return 0; }

ll N,M,cnt=0;
ll par[100010],r[100010];

void init(ll n){
    for(ll i=0;i<n;i++){
        par[i]=i;
        r[i]=0;
    }
}
ll root(ll x){
    if(par[x]==x) return x;
    else return par[x]=root(par[x]);
}
bool same(ll x,ll y){
    return root(x)==root(y);
}
void unite(ll x,ll y){
    x=root(x);
    y=root(y);
    if(x==y) return;
    if(r[x]<r[y]){
        par[x]=y;
    }else{
        par[y]=x;
        if(r[x]==r[y]) r[x]++;
    }
}

int main(){
    cin>>N>>M;
    init(N);
    vector<ll> p(N),x(M),y(M);
    for(ll i=0;i<N;i++) cin>>p[i];
    for(ll i=0;i<M;i++) cin>>x[i]>>y[i];

    for(ll i=0;i<M;i++) unite(x[i],y[i]);
    for(ll i=0;i<N;i++){
        if(same(i+1,p[i])) cnt++;
    }
    cout<<cnt<<endl;
}