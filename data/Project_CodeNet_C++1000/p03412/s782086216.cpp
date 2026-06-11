#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
#include<utility>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define prin(arg) std::cout<<arg<<"\n"
#define prin2(arg1,arg2) std::cout<<arg1<<" "<<arg2<<"\n"
#define fill(arg,n) memset(arg,n,sizeof(arg))
using std::cin;
typedef long long ll;
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
const int INF=1e+9;
const ll INFLL=1e+17;
int N;
ll a[200010],b[200010],aa[200010],bb[200010];
//二分探索
int upper(int l,int r,ll x){
  int lb=l-1,ub=r+1;
  while(ub-lb>1){
    int mid=(ub+lb)/2;
    if(x<=bb[mid]) ub=mid;
    else lb=mid;
  }
  return ub;
}/*
int lower(int l,int r,int x){
  int lb=l-1,ub=r+1;
  while(ub-lb>1){
    int mid=(ub+lb)/2;
    if(bb[mid]<x) lb=mid;
    else ub=mid;
  }
  return lb;
  }*/
//数列a,bのmodをとってsort
void make_ab(ll mod){
  rep(i,N){
    aa[i]=a[i]%mod;
    bb[i]=b[i]%mod;
  }
  std::sort(bb,bb+N);
}
void solve(){
  ll mod=2,res=0;
  rep(i,30){
    make_ab(mod);
    ll cnt=0;
    rep(j,N){
      cnt+=upper(0,N-1,mod-aa[j])-upper(0,N-1,mod/2-aa[j]);
      cnt+=upper(0,N-1,3*mod/2-aa[j])-upper(0,N-1,2*mod-aa[j]);
    }
    if(cnt%2==1) res+=mod/2;
    mod*=2;
  }
  prin(res);
}
int main(){
  cin>>N;
  rep(i,N) cin>>a[i];
  rep(i,N) cin>>b[i];  
  solve();
  return 0;
}
