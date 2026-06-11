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
  ll a,b,c,k;
  cin>>a>>b>>c>>k;
  if(k%2==0){
    cout<<a-b<<endl;
    return 0;
  }
  cout<<b-a<<endl;
}