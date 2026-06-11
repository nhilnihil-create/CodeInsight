#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<ll>> vvl;
typedef vector<ll> vl;
typedef vector<vector<char>> vvc;
typedef vector<char> vc;
typedef pair<ll,ll> pll;
typedef priority_queue<string> priquest;
typedef priority_queue<string,vector<string>,greater<string>> rpriquest;
ll max(ll x,ll y){
if(x>y)return x;
else return y;
}
ll min(ll x,ll y){
  return x+y-max(x,y);
}

const ll big=1000000007;
ll exp(ll x,ll y){
    if(y==0)return 1;
    if(x==1||x==0)return x;
    if(y%2==1)return (exp(x,y-1)*x);
    ll t=exp(x,y/2);
    return (t*t);
}
void chmin(ll a,ll b){
    if(a>b)a=b;
    return;
}

struct unionfind{
  vector<int> par;
  vector<ll> sizes;
  void begin(int n){
    par.resize(n,-1);
    sizes.resize(n,1);
  }
  
  int find(int x){
    if(par[x]==-1)return x;
    return par[x]=find(par[x]);
  }
  
  void unite(int x,int y){
    x=find(x);
    y=find(y);
    par[x]=y;//yが親
    sizes[y]+=sizes[x];
    sizes[x]=0;
  }
};



int main(){
  int n,m;cin >> n >> m;
  unionfind uf;
  uf.begin(n);
  vector<pair<int,int>> stdin(m-1);
  int aa,bb;cin >> aa >> bb;
  rep(i,m-1){
    cin >> stdin[m-i-2].first >> stdin[m-i-2].second;
  }
  ll ans=n*(n-1LL)/2LL;
  vector<ll> answer(m);
  answer[m-1]=ans;
  rep(i,m-1){
    int a=stdin[i].first;int b=stdin[i].second;
    a--;b--;
    if(uf.find(a)!=uf.find(b)){
      ans-=uf.sizes[uf.find(a)]*uf.sizes[uf.find(b)];
      uf.unite(a,b);
    }
    answer[m-i-2]=ans;
  }
  rep(i,m)cout << answer[i] << endl;
}