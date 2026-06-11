#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,ans=0,A=0,B=0,C=0;
  cin>>N;
  for(int k=0;k<N;k++){
    string S;
    cin>>S;
    int a=0,b=0;
    for(int i=0;i<S.size()-1;i++)
      if(S.substr(i,2)=="AB")
        ans++;
    if(S[0]=='B' && S[S.size()-1]=='A')
      C++;
    if(S[0]=='B')
      B++;
    if(S[S.size()-1]=='A')
      A++;
  }
  if(A==C && B==C && C>0)
    cout<<ans+C-1<<endl;
  else
    cout<<ans+min(A,B)<<endl;
}