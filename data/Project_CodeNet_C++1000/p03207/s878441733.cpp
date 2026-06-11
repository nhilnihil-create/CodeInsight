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
  sort(begin(A),end(A));
  int ans=0;
  rep(i,N-1)ans+=A[i];
  ans+=A[N-1]/2;
  cout<<ans<<endl;
}