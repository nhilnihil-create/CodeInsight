#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,Q;
  string S;
  cin>>N>>S>>Q;
  while(Q--){
    int k,ans=0,D=0,M=0,DM=0;
    cin>>k;
    for(int i=0;i<N;i++){
      if(i>=k){
        if(S[i-k]=='D')D--,DM-=M;
        else if(S[i-k]=='M')M--;
      }
      if(S[i]=='D')D++;
      else if(S[i]=='M')M++,DM+=D;
      else if(S[i]=='C') ans+=DM;
    }
    cout<<ans<<endl;
  }
}