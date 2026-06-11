#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,K,ans=0;
  cin>>N>>K;
  vector<int> A(N);
  for(int &i:A)cin>>i;
  for(int i=0;i<=K && i<=N;i++){
    for(int j=0;j+i<=K && i+j<=N;j++){
      priority_queue<int,vector<int>,greater<int>> Q;
      int sum=0;
      for(int k=0;k<i;k++){
        Q.push(A[k]);
        sum+=A[k];
      }
      for(int k=0;k<j;k++){
        Q.push(A[N-1-k]);
        sum+=A[N-1-k];
      }
      for(int k=0;i+j+k<K && k<i+j;k++){
        if(Q.top()>=0)break;
        sum-=Q.top();
        Q.pop();
      }
      ans=max(ans,sum);
    }
  }
  cout<<ans<<endl;
}