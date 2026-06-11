#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  string S;
  cin>>S;
  
  int ans=0;
  
  bool res=true;
  
  
  for(int i=0;i<S.size();i++){
    if(S[i]=='A'||S[i]=='C'||S[i]=='G'||S[i]=='T'){
      res=false;
    }
  }
  if(res){
    cout<<0<<endl;
  }
  else{
  for(int i=0;i<S.size();i++){
    int x=1;
    if(S[i]=='A'||S[i]=='C'||S[i]=='G'||S[i]=='T'){
      while(true){
        if(S[i+1]=='A'||S[i+1]=='C'||S[i+1]=='G'||S[i+1]=='T'){
          x++;
          i++;
        }
        else{
          break;
        }
      }
    }
    ans=max(ans,x);
  }
  
  cout<<ans<<endl;
  }
}