#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,C;
  cin>>N>>C;
  vector<vector<int>> A(C,vector<int>(C));
  for(int i=0;i<C;i++)
    for(int &j:A[i])
      cin>>j;
  vector<vector<int>> B(3,vector<int>(C,0));
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
        for(int l=0;l<C;l++){
          if(i!=l)cnt+=B[0][l]*A[l][i];
          if(j!=l)cnt+=B[1][l]*A[l][j];
          if(k!=l)cnt+=B[2][l]*A[l][k];
        }
        ans=min(ans,cnt);
      }
    }
  cout<<ans<<endl;
}