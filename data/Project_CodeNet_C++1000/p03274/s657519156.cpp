#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,M;cin>>N>>M;
  vector<int>A(N);
  int ans=1000000000;
  for(int i=0;i<N;i++)cin>>A[i];
  for(int i=M-1;i<N;i++){
    if(A[i-M+1]>=0)ans=min(ans,A[i]);
    else if(A[i]<=0)ans=min(ans,abs(A[i-M+1]));
    else ans=min(min(ans,A[i]*2+abs(A[i-M+1])),abs(A[i-M+1])*2+A[i]);
  }
  cout<<ans<<endl;
}