#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,C;
  cin>>N>>C;
  vector<vector<int>> A(C,vector<int>(C)),B(3,vector<int>(C));
  for(int i=0;i<C;i++)
    for(int &j:A[i])cin>>j;
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++){
      int a;
      cin>>a;
      B[(i+j)%3][a-1]++;
    }
  int ans=1000000000000000000;
  for(int i=0;i<C;i++)
    for(int j=0;j<C;j++){
      if(i==j)continue;
      for(int k=0;k<C;k++){
        if(i==k || j==k)continue;
        int cnt=0;
        for(int l=0;l<C;l++)cnt+=A[l][i]*B[0][l]+A[l][j]*B[1][l]+A[l][k]*B[2][l];
        ans=min(ans,cnt);
      }
    }
  cout<<ans<<endl;
}