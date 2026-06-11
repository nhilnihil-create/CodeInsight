#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,M;
  cin>>N>>M;
  vector<int[3]> A(N);
  for(int i=0;i<N;i++)cin>>A[i][0]>>A[i][1]>>A[i][2];
  int ans=0;
  for(int bit=0;bit<8;bit++){
    vector<int> B(N,0);
    for(int i=0;i<N;i++)
      for(int j=0;j<3;j++){
        if((bit>>j)&1)B[i]+=A[i][j];
        else B[i]-=A[i][j];
      }
    sort(B.rbegin(),B.rend());
    int cnt=0;
    for(int i=0;i<M;i++)cnt+=B[i];
    ans=max(ans,cnt);
  }
  cout<<ans<<endl;
}