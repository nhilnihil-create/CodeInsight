#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  string S,T="";
  cin>>S;
  S+="B";
  int N=S.size(),ans=0;
  for(int i=0,j=0;i<N;i++){
    if(S[i]=='A')
      T+='0';
    else if(i<N-1 && S.substr(i,2)=="BC")
      T+='1',i++;
    else{
      int n=0;
      for(char c:T){
        if(c=='1')
          ans+=n;
        else
          n++;
      }
      T="";
    }
  }
  cout<<ans<<endl;
}