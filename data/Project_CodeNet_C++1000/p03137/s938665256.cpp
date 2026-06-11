#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,M;
  cin>>N>>M;
  vector<int> A(M),B(M-1);
  for(int &i:A)cin>>i;
  sort(A.begin(),A.end());
  for(int i=0;i<M-1;i++)B[i]=A[i+1]-A[i];
  sort(B.begin(),B.end());
  int ans=0;
  for(int i=0;i+N<M;i++)ans+=B[i];
  cout<<ans<<endl;
}