#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int n; cin>>n;
  ll sum=0;
  vector<ll> num(n);
  for(int i=0;i<n;i++){
    ll a,b; cin>>a>>b;
    num[i]=a+b;
    sum+=b;
  }
  sort(num.rbegin(),num.rend());
  ll ans=0;
  for(int i=0;i<n;i+=2){
    ans+=num[i];
  }
  cout<<ans-sum<<endl;
}