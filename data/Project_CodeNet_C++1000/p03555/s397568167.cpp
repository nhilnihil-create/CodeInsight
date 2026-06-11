#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  string S,T;
  cin>>S>>T;
  for(ll i=0;i<3;i++) {
if(S[i]!=T[2-i]) {
  cout<<"NO"<<endl;
  return 0;
}
  }
  
  cout<<"YES"<<endl;
}
