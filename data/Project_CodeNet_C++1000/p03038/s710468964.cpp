#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N,M;
  cin>>N>>M;
  vector<pair<int,int>> A(N+M);
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    A[i]=make_pair(a,1);
  }
  for(int i=0;i<M;i++){
    int b,c;
    cin>>b>>c;
    A[N+i]=make_pair(c,b);
  }
  sort(A.begin(),A.end());
  int j=0,k=0;
  for(int i=N+M-1;i>=0;i--){
    if(k+A[i].second<N){
      j+=A[i].first*A[i].second;
      k+=A[i].second;
    }else{
      cout<<j+A[i].first*(N-k)<<endl;
      return 0;
    }
  }
}