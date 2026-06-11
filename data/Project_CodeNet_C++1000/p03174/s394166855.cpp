#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1000000007;
signed main(){
  int N;
  cin>>N;
  vector<vector<int>> A(N,vector<int>(N));
  for(vector<int> &v:A)
    for(int &i:v)
      cin>>i;
  vector<int> B(1<<N,0);
  B[0]=1;
  for(int i=0;i<(1<<N);i++){
    int n=__builtin_popcount(i);
    for(int j=0;j<N;j++){
      if((!(i & (1<<j))) && A[n][j])
        B[i^(1<<j)]=(B[i^(1<<j)]+B[i])%mod;
    }
  }
  cout<<B[(1<<N)-1]<<endl;
}