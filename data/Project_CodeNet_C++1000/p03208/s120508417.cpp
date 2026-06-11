#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,K;
  cin>>N>>K;
  vector<int> A(N);
  for(int &i:A)cin>>i;
  sort(A.begin(),A.end());
  int ans=10000000000;
  for(int i=0;i+K-1<N;i++)ans=min(ans,A[i+K-1]-A[i]);
  cout<<ans<<endl;
}