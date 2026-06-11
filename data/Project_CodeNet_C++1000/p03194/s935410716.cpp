#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long
int main(){
  IOS
  ll n,p;
  cin>>n>>p;
  ll c=0;
  while(p%2==0){
   c++;
   p/=2;
}
  c/=n;
  ll ans=pow(2,c);
  for(ll i=3;i<=sqrt(p);i+=2){
   ll c=0;
   while(p%i==0){
   p/=i;
   c++;
}
  c/=n;
  ans=ans*pow(i,c);
}
  if(p>2){
   if(n==1){ ans*=p;}
}
  cout<<ans;
  return 0;
}