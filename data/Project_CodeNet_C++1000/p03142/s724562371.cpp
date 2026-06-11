#include<bits/stdc++.h>
//ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<pii,int> ppii;
typedef pair<int,pii> pipi;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> ppll;
typedef pair<ll,pll> plpl;
typedef tuple<ll,ll,ll> tl;
ll mod=1000000007;
ll mod2=998244353;
ll mod3=1000003;
ll mod4=998244853;
ll inf=1000000000000000000;
double pi=2*acos(0);
#define rep(i,m,n) for(ll i=m;i<n;i++)
#define rrep(i,n,m) for(ll i=n;i>=m;i--)
int dh[4]={1,-1,0,0};
int dw[4]={0,0,1,-1};
int ddh[8]={-1,-1,-1,0,0,1,1,1};
int ddw[8]={-1,0,1,-1,1,-1,0,1};
ll lmax(ll a,ll b){
    if(a<b)return b;
    else return a;
}
ll lmin(ll a,ll b){
    if(a<b)return a;
    else return b;
}
ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    if(a%b==0)return b;
    return gcd(b,a%b);
}
ll Pow(ll n,ll k){
    ll ret=1;
    ll now=n;
    while(k>0){
        if(k&1)ret*=now;
        now*=now;
        k/=2;
    }
    return ret;
}
ll par[800010];
ll len[800010];
void init(ll n){
    for(int i=0;i<n;i++){
        par[i]=i;
        len[i]=0;
    }
}
ll root(ll n){
    if(par[n]==n)return n;
    return par[n]=root(par[n]);
}
void unit(ll a,ll b){
    a=root(a);
    b=root(b);
    if(a==b)return;
    if(len[a]<len[b]){
        par[a]=b;
    }
    else{
        par[b]=a;
        if(len[a]==len[b])len[a]++;
    }
}
struct edge{
    ll from,to,cost;
};
bool cmp(edge a,edge b){
    return a.cost<b.cost;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    ll n,m;cin>>n>>m;
    vector<ll> v[n+1],w[n+1];
    rep(i,0,n+m-1){
        ll a,b;cin>>a>>b;
        v[a].push_back(b);
        w[b].push_back(a);
    }
    queue<ll> q;
    rep(i,1,n+1){
        if(v[i].size()==0)q.push(i);
    }
    ll cnt[n+1];
    fill(cnt,cnt+n+1,0);
    ll par[n+1];
    fill(par,par+n+1,0);
    while(q.size()>0){
        ll now=q.front();q.pop();
        rep(i,0,v[now].size()){
            ll ne=v[now][i];
            if(par[ne]>0)continue;
            par[ne]=now;
        }
        rep(i,0,w[now].size()){
            ll ne=w[now][i];
            cnt[ne]++;
            if(v[ne].size()==cnt[ne]){
                q.push(ne);
            }
        }
        
    }
    rep(i,1,n+1)cout<<par[i]<<endl;
}
