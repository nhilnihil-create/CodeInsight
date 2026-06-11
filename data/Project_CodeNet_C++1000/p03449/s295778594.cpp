#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  cin>>N;
  vector<int> A(N+1),B(N+1);
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    A[i+1]=A[i]+a;
  }
  for(int i=0;i<N;i++)cin>>B[i];
  for(int i=N-1;i>=0;i--)B[i]+=B[i+1];
  int ans=0;
  for(int i=0;i<N;i++)ans=max(ans,A[i+1]+B[i]);
  cout<<ans<<endl;
}