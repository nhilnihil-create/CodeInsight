// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(10);
}
template <typename Monoid >
struct SegmentTree{
  using F = function< Monoid(Monoid,Monoid) >;

  int sz;
  vector<Monoid> seg;

  const F f;
  const Monoid M;

  SegmentTree(int n,const F f,const Monoid &M) : f(f),M(M){
    sz = 1;
    while(sz<n) sz<<=1;
    seg.assign(sz*2,M);
  }
  void set(int k,const Monoid &v){
    seg[k+sz] = v;
  }
  void build(){
    for(int k=sz-1;k>0;k--){
      seg[k] = f(seg[2*k],seg[2*k+1]);
    }
  }
  void update(int k,const Monoid &v){
    k += sz;
    seg[k] = v;
    while(k >>= 1){
      seg[k] = f(seg[2*k],seg[2*k+1]);
    }
  }
  Monoid que(int a,int b){
    Monoid L=M,R=M;
    for(a+=sz, b+=sz;a<b;a>>=1,b>>=1){
      if(a&1) L = f(L,seg[a++]);
      if(b&1) R = f(seg[--b],R);
    }
    return f(L,R);
  }
  Monoid operator[](const int &k) const{
    return seg[k+sz];
  }
};
signed main(){
  init_io();
  ll n,l=0,r=1100000000,h,cnt;
  cin >> n;
  ll m = ((n*(n+1))/2)/2;
  vector<ll> a(n),ca(n),s(n+1);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  ll base = n+1;
  while(r-l>1){
    ll sum = 0;
    cnt = 0;
    h = (r+l)/2;
    SegmentTree<ll> seg(2*n+10,[](ll a,ll b){return a+b;},0);
    vector<P> tmp(n);
    seg.update(sum+base,1);
    for(int i=0;i<n;i++){
      if(a[i]<=h) ca[i] = 1;
      else ca[i] = -1;
      sum += ca[i];
      cnt += seg.que(1,sum+base);
      seg.update(sum+base,seg[sum+base]+1);
    }
    if(cnt>m){
      r = h;
    }else{
      l = h;
    }
  }
  cout << r << endl;
}
