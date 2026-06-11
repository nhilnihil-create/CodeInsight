#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
string S;
  cin>>S;
  for(ll i=0;i<3;i++) {
    if(S[i]=='1') {
      S[i]='9';
    }
    else if(S[i]=='9') {
      S[i]='1';
    }
  }
  
  cout<<S<<endl;
}