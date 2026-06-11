#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()

ll sum(ll n) {
if(n==0) {
return 0;
}
  ll s=n+sum(n-1);
  return s;
}
 
int main() {
 ll a,b;
  cin>>a>>b;
  ll x=sum(b-a-1);
  
  cout<<x-a<<endl;
}
  
  
  
