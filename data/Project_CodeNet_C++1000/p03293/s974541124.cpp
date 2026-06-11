#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 string S,T;
  cin>>S>>T;
  
  if(S==T) {
cout<<"Yes"<<endl;
    return 0;
  }
for(ll i=0;i<S.size();i++) {
  bool a=true;
  ll h=0;
  ll count=0;
  ll j=i;
while(count<S.size()) {

if(j==S.size()) {
j-=S.size();
}
  if(S[j]!=T[h]) {
    a=false;
  }
  h++;
  j++;
  count++;
}
  
  if(a) {
cout<<"Yes"<<endl;
    return 0;
  }
}
  
  
  
  cout<<"No"<<endl;
}

  
  
  
  
  
  
