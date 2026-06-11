#include<bits/stdc++.h>
using namespace std;
int main(){
  string S; cin>>S;
  sort(S.begin(),S.end());
  string ans="No";
  if(S=="abc") ans="Yes";
  cout<<ans<<endl;
}