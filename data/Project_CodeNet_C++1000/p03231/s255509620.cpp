#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
ll gcd(ll a, ll b){
  if(b == 0){
    return a;
  }
  else{
    return gcd(b,(a%b));
  }
}
ll lcm(ll a,ll b){
  return a/gcd(a,b)*b;
}

int main() {
  ll n,m;
  string s,t;
  cin>>n>>m>>s>>t;
  if(n>m){
    swap(n,m);
    swap(s,t);
  }
  ll ans=lcm(n,m);
  ll p=ans/n,q=ans/m;
  for(int i=0;i<n;i++){
    if((i*p)%q==0){
      if(s.at(i)!=t.at((i*p)/q)){
      cout<<-1<<endl;
      return 0;
      }
    }
  }
  cout<<ans<<endl;
}