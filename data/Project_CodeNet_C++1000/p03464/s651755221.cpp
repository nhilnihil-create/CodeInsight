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
ll mpower(ll a,ll b,ll c){
  int z;
  if(b==0){
    z=1;
    z%=c;
    return z;
  }
  if(b==1){
    z=a;
    z%=c;
    return z;
  }
  else{
    return (((mpower(a,b/2,c))*(mpower(a,b/2,c))%c)*mpower(a,b%2,c)%c);
  }
}

int main() {
  int n;
  cin>>n;
  ll vec[n];
  for(int i=0;i<n;i++){
    cin>>vec[i];
  }
  if(vec[n-1]!=2){
    cout<<-1<<endl;
    return 0;
  }
  ll p=n;
  p*=1100000000;
  ll ng=1,ok=p;
  ll a,b;
  for(int j=0;j<200;j++){
    a=(ng+ok)/2;
    b=a;
    for(int i=0;i<n;i++){
      b=(b/vec[i])*vec[i];
    }
    if(b<2){
      ng=a;
    }
    else{
      ok=a;
    }
  }
  b=ok;
  for(int i=0;i<n;i++){
    b=(b/vec[i])*vec[i];
  }
  //cout<<ng<<ok<<endl;
  if(b!=2){
    cout<<-1<<endl;
    return 0;
  }
  cout<<ng+1<<" ";
  ok=p;
  for(int j=0;j<200;j++){
    a=(ng+ok)/2;
    b=a;
    for(int i=0;i<n;i++){
      b=(b/vec[i])*vec[i];
    }
    if(b<3){
      ng=a;
    }
    else{
      ok=a;
    }
  }
  cout<<ok-1<<endl;
}