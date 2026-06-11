#include <bits/stdc++.h>
using namespace std;
signed main(){
  char s[200];
  int a;
  cin>>s;
  for(int i=60;i>=0;i--){
    if(s[i]=='F'){
      a=i;
      break;
    }
  }
  for(int i=0;i<a;i++)
    cout<<s[i];
  cout<<endl;
  return(0);
}
    
