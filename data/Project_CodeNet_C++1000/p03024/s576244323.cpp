#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;cin>>S;
  if(count(S.begin(),S.end(),'x')<8)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}