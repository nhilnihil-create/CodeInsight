// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(10);
}
const ll MAX_N = 2e5;
vector<ll> G[MAX_N],GR[MAX_N];
vector<ll> vlist;
vector<bool> used(MAX_N,false);
ll n,m;
void dfs(ll v){
  if(used[v]) return;
  used[v] = true;
  for(auto nv:G[v]){
    dfs(nv);
  }
  vlist.push_back(v);
}
void tsort(){
  for(int i=0;i<n;i++){
    dfs(i);
  }
  reverse(vlist.begin(),vlist.end());
}
signed main(){
  init_io();
  cin >> n >> m;
  vector<ll> a(n-1+m),b(n-1+m),tp_idx(n,0);
  for(int i=0;i<n-1+m;i++){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    G[a[i]].push_back(b[i]);
    GR[b[i]].push_back(a[i]);
  }
  tsort();
  ll p=vlist[0];
  for(int i=0;i<n;i++){
    tp_idx[vlist[i]] = i;
  }
  for(int i=0;i<n;i++){
    if(p==i){
      cout <<0<<endl;
    }else{
      ll mv=GR[i].front();
      for(auto v:GR[i]){
        if(tp_idx[mv]<tp_idx[v]){
          mv = v;
        }
      }
      cout << mv+1 << endl;
    }
  }
}
