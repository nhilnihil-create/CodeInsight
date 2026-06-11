#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
const ll mod=998244353;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
V<int> graph[200005];
V<int> dist;
int max_dist;
void dfs(int now,int par){
    for(int v:graph[now]){
        if(v==par)continue;
        dfs(v,now);
    }
    int ma1=0,ma2=-1;
    for(int v:graph[now]){
        if(v==par)continue;
        if(ma1<=dist[v]){
            chmax(ma2,ma1);
            ma1=dist[v];
        }
        else if(ma2<=dist[v])ma2=dist[v];
    }
    if(ma2!=-1)chmax(max_dist,ma1+ma2);
    else chmax(max_dist,ma1);
    dist[now]=ma1+1;
    return;
}
int main(){
    int n;
    cin>>n;
    max_dist=0;
    dist.assign(n,0);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    if(n==1){
        cout<<"First"<<"\n";
        return 0;
    }
    dfs(0,-1);
    max_dist--;
    if(max_dist%3==0)cout<<"Second"<<"\n";
    else cout<<"First"<<"\n";
}