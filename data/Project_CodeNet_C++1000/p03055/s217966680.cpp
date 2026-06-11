#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<int,int>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
ll GCD(ll a,ll b) {return b ? GCD(b,a%b):a;}
ll LCM(ll c,ll d){return c/GCD(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int ma=0;
int ind;
V<int> g[200005];
void dfs(int cur,int par,int now){
  if(chmax(ma,now))ind=cur;
  for(int v:g[cur]){
    if(v==par)continue;
    dfs(v,cur,now+1);
  }
}
int main(){
  int n;
  cin>>n;
  for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    g[--a].push_back(--b);
    g[b].push_back(a);
  }
  dfs(0,-1,0);
  ma=0;
  dfs(ind,-1,0);
  cout<<(ma%3%2==0?"First":"Second")<<"\n";
}
