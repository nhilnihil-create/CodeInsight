#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 ll s;
  cin>>s;
  set<ll> S;
  S.insert(s);
 for(ll i=2;i<10000000;i++) {
 if(s%2==0) {
s/=2;
 }
   else {
s=s*3+1;
   }
   if(S.count(s)) {
cout<<i<<endl;
     return 0;
   }
   
   S.insert(s);
 }
}
  