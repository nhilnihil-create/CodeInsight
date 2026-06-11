#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll n,x;
  cin>>n>>x;
  vector<ll> a(n);
  rep(i,n){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  ll ans=0;
  rep(i,n){
    x-=a[i];
    if(x==0){
      ans++;
      break;
    }
    if(x<0){
      break;
    }
    ans++;
  }
  if(x>0){
    ans--;
  }
  cout<<ans<<endl;
}