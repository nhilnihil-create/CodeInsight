#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N,M,Q;
  cin>>N>>M>>Q;
  vector<vector<int>> A(N+1,vector<int>(N+1));
  for(int i=0;i<M;i++){
    int L,R;
    cin>>L>>R;
    A[L][R]++;
  }
  for(int i=0;i<=N;i++)
    for(int j=1;j<=N;j++)
      A[i][j]+=A[i][j-1];
  for(int j=0;j<=N;j++)
    for(int i=1;i<=N;i++)
      A[i][j]+=A[i-1][j];
  for(int i=0;i<Q;i++){
    int p,q;
    cin>>p>>q;
    cout<<A[q][q]+A[p-1][p-1]-A[p-1][q]-A[q][p-1]<<endl;
  }
}