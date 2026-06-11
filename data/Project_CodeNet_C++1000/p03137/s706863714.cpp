#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,M; cin>>N>>M; if(N>=M){cout<<0<<endl; return 0;}
  vector<int>A(M);for(int i=0;i<M;i++)cin>>A[i];
  sort(A.begin(),A.end());
  vector<int>B(M-1);for(int i=0;i<M-1;i++)B[i]=A[i+1]-A[i];
  sort(B.begin(),B.end());
  int ans=0;
  for(int i=0;i<M-N;i++)ans+=B[i];
  cout<<ans<<endl;
}