
#include <bits/stdc++.h>  
using namespace std;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
using ll = long long int;
using pll = pair<ll, ll>;


int main() {
  ll n,m; cin>>n>>m;
  vector<ll> v(n);
  rep(i,n){cin>>v[i];}
  sort(v.begin(),v.end());
  vector<pll> vec(m);
  rep(i,m){
    cin>>vec[i].second>>vec[i].first;
  }
  sort(vec.begin(), vec.end(), greater<pll>());
  ll k=0;
  rep(i,m){
    rep(j,vec[i].second){
      if(v[k]>=vec[i].first){break;}
      v[k]=vec[i].first;
      k++;
      if(k==n){break;}
    }
  }
  ll sum=0;
  rep(i,n){sum+=v[i];}
  cout<<sum<<endl;
}