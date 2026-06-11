#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,K;
  string S;
  cin>>N>>K>>S;
  vector<int> B(0);
  char c;
  for(int i=0;i<N;i++){
    if(S[i]!=c){
      B.push_back(i);
      c=S[i];
    }
  }
  int M=B.size();
  for(int i=0;i<=2*K;i++)
    B.push_back(N);
  int ans=0;
  for(int i=0;i<M;i++){
    if(S[B[i]]=='0')
      ans=max(ans,B[i+2*K]-B[i]);
    else
      ans=max(ans,B[i+2*K+1]-B[i]);
  }
  cout<<ans<<endl;
}