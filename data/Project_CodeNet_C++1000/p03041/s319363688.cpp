#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 ll N,K;
  cin>>N>>K;
  string S;
  cin>>S;
  for(ll i=0;i<N;i++) {
 if(i==K-1) {
if(S[i]=='A') {
  cout<<"a";
}
   else if(S[i]=='B') {
cout<<"b";
   }
else {
  cout<<"c";
}
 }
    
    else {
      cout<<S[i];
    }
  }
  
  cout<<endl;
}
  
