#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,M;
  cin>>N>>M;
  vector<int> A(M,true);
  for(int i=0;i<N;i++){
    int K;
    cin>>K;
    vector<int> B(M,false);
    for(int j=0;j<K;j++){
      int a;
      cin>>a;
      B[a-1]=true;
    }
    for(int j=0;j<M;j++)
      A[j]=A[j]&&B[j];
  }
  int ans=0;
  for(bool b:A)
    if(b)
      ans++;
  cout<<ans<<endl;
}