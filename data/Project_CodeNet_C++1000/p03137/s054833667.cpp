#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
  ll n,m;
  cin>>n>>m;
  if(n>=m){
    cout<<"0";
    return 0;
  }
  vector<ll> x(m),a(m-1);
  rep(i,m){
  	cin>>x[i];
  }
  sort(x.begin(),x.end());
 
  for(ll i=m-2;i>=0;i--){
  	a[i]=x[i+1]-x[i];
  }
  
  sort(a.begin(),a.end());
  
  int64_t ans=x[m-1]-x[0];
  
  rep(i,n-1){
  	ans-=a[m-2-i];
  }
  cout<<ans<<endl;
}
