#include<bits/stdc++.h>
using namespace std;
int main(){
  string s,t;
  cin>>s>>t;
  int m,n,i,j,k;
  m=s.length();
  n=t.length();
  if(m<n){
    cout<<"UNRESTORABLE"<<endl;
    return 0;
  }
  for(i=0;i<=m-n;i++){
    for(j=0;j<n;j++){
      if(s.at(m-n-i+j)!='?'&&s.at(m-n-i+j)!=t.at(j)) break;
    }
    if(j==n){
      for(k=0;k<m-n-i;k++){
        if(s.at(k)=='?') cout<<'a';
        else cout<<s.at(k);
      }
      cout<<t;
      for(k=0;k<i;k++){
        if(s.at(m-i+k)=='?') cout<<'a';
        else cout<<s.at(m-i+k);
      }
      cout<<endl;
      return 0;
    }
  }
  cout<<"UNRESTORABLE"<<endl;
}