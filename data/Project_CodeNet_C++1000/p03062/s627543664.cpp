#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n;
  cin >> n;
  vector<ll> a(n),cp(n);
  ll p=0,sum=0;
  rep(i,n){
    cin >> a.at(i);
    cp.at(i)=abs(a.at(i));
    sum+=cp.at(i);
    if(a.at(i)<0){
      p++;
    }
  }
  if(p%2==1){
    ll mini=1e11;
    for(ll j=0;j<n;j++){
      mini=min(mini,cp.at(j));
    }
    sum=sum-2*mini;
  }
  cout << sum;
}
    
  
  