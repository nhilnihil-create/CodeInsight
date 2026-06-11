#include<bits/stdc++.h>
using namespace std;
signed main(){
  string a,b,c="AKIHABARA";
  bool q=false;
  cin>>a;
  for(int i=0;i<a.size();i++){
    if(i==0&&a[i]!='A') b+='A';
    b+=a[i];
    if((a[i]=='H'||a[i]=='B'||a[i]=='R')&&b.size()>=3){
      if(a[i+1]!='A') b+='A';
    }
  }
  for(int i=0;i<c.size();i++){
    if(b[i]!=c[i]) q=true;
  }
  if(!q&&b.size()==c.size()) cout<<"YES";
  else cout<<"NO";
  cout<<"\n";
}