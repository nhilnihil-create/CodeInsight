#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 string S;
  cin>>S;
  if(S[0]!='A') {
cout<<"WA"<<endl;
    return 0;
  }
  ll count=0;
  ll index;
  for(ll i=2;i<S.size()-1;i++) {
    if(S[i]=='C') {
index=i;
      count++;
    }
  }
  
  if(count!=1) {
cout<<"WA"<<endl;
    return 0;
  }
  for(ll i=1;i<S.size();i++) {
if(i==index) {
continue;
}
    if(S[i]-'a'<0) {
cout<<"WA"<<endl;
      return 0;
    }
  }
  
  
  cout<<"AC"<<endl;
}
  
  

  
  
  
  
  
