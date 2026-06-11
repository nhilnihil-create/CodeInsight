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
  int n,q; cin>>n>>q;
  string s; cin>>s;
  vector<int> count(n);
  count[0]=0;
  for(int i=1; i<n ; i++){
    count[i]=count[i-1];
    if(s[i]=='C' && s[i-1]=='A'){
      count[i]=count[i-1]+1;
    }
    //cout<<count[i]<<endl;
  }
  rep(i,q){
    int l,r; cin>>l>>r;
    l--;r--;
    cout<<count[r]-count[l]<<endl;
  }



}
