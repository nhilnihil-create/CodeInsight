#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 ll A,B;
  cin>>A>>B;
  string S;
  cin>>S;
  if(S[A]!='-') {
cout<<"No"<<endl;
  return 0;
  }
  for(ll i=0;i<A+B+1;i++) {
if(i==A) {
continue;
}
    if(S[i]-'0'<0||S[i]-'0'>9) {
cout<<"No"<<endl;
      return 0;
    }
  }
  
  cout<<"Yes"<<endl;
}