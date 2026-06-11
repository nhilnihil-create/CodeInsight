#include<bits/stdc++.h>
using namespace std;

int main(){
  int A,B; cin>>A>>B;
  string S; cin>>S;
  string ans="Yes";
  for(int i=0; i<A+B+1; i++){
    if(i==A&&S[i]!='-')ans="No";
    if(i!=A&&S[i]=='-')ans="No";
  }
  cout<<ans<<endl;
  return 0;
}