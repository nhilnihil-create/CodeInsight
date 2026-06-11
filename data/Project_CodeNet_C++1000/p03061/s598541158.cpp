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

int main(){
  int n;
  cin>>n;
  ll vec[n];
  for(int i=0;i<n;i++){
    cin>>vec[i];
  }
  if(n==1){
    cout<<vec[0]<<endl;
    return 0;
  }
  ll vecgcd[n];
  ll vecgcdb[n];
  vecgcd[0]=vec[0];
  for(int i=1;i<n;i++){
    vecgcd[i]=gcd(vecgcd[i-1],vec[i]);
  }
  vecgcdb[n-1]=vec[n-1];
  for(int i=n-2;i>=0;i--){
    vecgcdb[i]=gcd(vecgcdb[i+1],vec[i]);
  }
  ll ans=0;
  for(int i=0;i<n;i++){
    if(i==0){
      ans=max(ans,vecgcdb[1]);
      continue;
    }
    if(i==n-1){
      ans=max(ans,vecgcd[n-2]);
      continue;
    }
    ans=max(ans,gcd(vecgcd[i-1],vecgcdb[i+1]));
  }
  cout<<ans<<endl;
}
