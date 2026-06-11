#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int N,K;
  cin>>N>>K;
  vector<int> A(N);
  rep(i,N)cin>>A[i];
  sort(begin(A),end(A));
  int I=0,ans=1e10+7;
  K-=1;
  while(K<=N-1){
    ans=min(A[K]-A[I],ans);
    K+=1;
    I+=1;
  }
  cout<<ans<<endl;
}