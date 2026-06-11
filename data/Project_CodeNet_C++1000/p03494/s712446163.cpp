#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int N;
  cin>>N;
  vector<int> A(N);
  rep(i,N)cin>>A[i];
  int ans=100000;
  rep(i,N){
    int J=0;
    while(A[i]%2==0){
      J+=1;
      A[i]/=2;
    }
    if(ans>J)ans=J;
  }
  cout<<ans<<endl;
  return 0;
}