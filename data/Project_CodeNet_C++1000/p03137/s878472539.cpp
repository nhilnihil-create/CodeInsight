#include <bits/stdc++.h>
#include <random>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;
const ll Lmax=ll(1e18);
const ll INF=1e6;
const int Nmax=2e5+1;
const int Nd=61;



int main(){
  int n,m; cin>>n>>m;
  vector<int> x(m);
  rep(i,m) {cin>>x[i];}
  sort(x.begin(),x.end());
  if(n>=m){
    cout<<0<<endl;
    return 0;
  }
  vector<int> l(m-1);
  rep(i,m-1) {
     l[i]=x[i+1]-x[i];
     //cout<<l[i]<<" ";
  }
  sort(l.begin(),l.end());
  int ans=x[m-1]-x[0];
  rep(i,n-1){
    ans-= l[m-2-i];
  }
  cout<<ans<<endl;





}
