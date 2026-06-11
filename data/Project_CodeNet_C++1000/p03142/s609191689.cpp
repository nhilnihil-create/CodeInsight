#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef unsigned  uint;
typedef unsigned long long int ull;
typedef pair<ll,ll> P;
typedef pair<P,long double> Pi;
typedef pair <long double,int> Pd;
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=1000000007;
const uint mod=998244353;
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
vector<vector<int>> graph,ch;
int main(){
ios::sync_with_stdio(false);
cin.tie(NULL);
int n,m;
cin>>n>>m;
graph.resize(n);
ch.resize(n);
for(int i=0;i<n+m-1;i++){
    int a,b;
    cin>>a>>b;
    --a;--b;
    graph[a].push_back(b);
    ch[b].push_back(a);
}
int par=0;
for(int i=0;i<n;i++){
    if(ch[i].size()==0){
        par=i;
        break;
    }
}
vector<P> ans(n,P(0,0));
queue<P> q;
q.push(P(par,0));
vector<int> used_times(n,0);
while(!q.empty()){
    P p=q.front();
    q.pop();
    for(int v:graph[p.fi]){
        if(ch[v].size()!=1){
            used_times[v]++;
             if(used_times[v]!=ch[v].size())continue;
        }
        ans[v]=P(p.fi+1,p.se);
         q.push(P(v,p.se+1));
        }
    }
for(int i=0;i<n;i++){
    cout<<ans[i].fi<<endl;
}
}
