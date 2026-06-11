#include<bits/stdc++.h>
using ll=long long;
using namespace std;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}

int main(){
  int n,m;
  cin>>n>>m;
  vector<int>l(m);
  vector<int>r(m);
  rep(i,m)cin>>l[i]>>r[i];

  vector<int>gate(n);
  int lmax=1;
  int rmin=n;
  rep(i,m){
    lmax=max(l[i],lmax);
    rmin=min(r[i],rmin);

  }
  if(lmax>rmin)cout<<0<<endl;
  else cout<<rmin-lmax+1<<endl;
  
    
    
  return 0;
}
