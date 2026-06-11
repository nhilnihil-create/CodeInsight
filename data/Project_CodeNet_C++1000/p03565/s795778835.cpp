#include<bits/stdc++.h>
using namespace std;
using int64 = long long;
const int mod = 1e9 + 7;
const long long INF = 1e18;
#define PI 3.141592653589793
  int main()
{
  string S,T,ans="UNRESTORABLE";
  int W=0;
  cin>>S>>T;
  
  for(int i=0;i<S.size();i++){
    W=0;
    for(int j=0;j<T.size();j++){
      if(S[i+j]==T[j]||S[i+j]=='?'){
        W++;
      }else{
        break;
      }
    }
    if(W==T.size()){
      ans=S;
      for(int j=0;j<S.size();j++){
        if(ans[j]=='?')ans[j]='a';
      }
      for(int j=0;j<T.size();j++){
        ans[j+i]=T[j];
      }
      ans[S.size()]='\0';
    }
  }
  cout<<ans;
  return 0;
}

