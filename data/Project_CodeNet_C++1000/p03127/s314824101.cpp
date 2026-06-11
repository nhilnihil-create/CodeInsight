#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a,ll b){
  if(b==0){
    return a;
  }
  else{
    return gcd(b,(a%b));
  }
}

int main(){
  int n;
  cin>>n;
  ll ans;
  cin>>ans;
  for(int i=1;i<n;i++){
    ll p;
    cin>>p;
    ans=gcd(p,ans);
  }
  cout<<ans<<endl;
}