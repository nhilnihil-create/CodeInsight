#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int N;
  cin>>N;
  vector<int> A(N),B(N);
  rep(i,N)cin>>A[i];
  rep(i,N)cin>>B[i];
  int ans=0;
  rep(i,N){
    int Mans=0;
    rep(j,N){
      if(j<=i){
        Mans+=A[j];
      }
      if(j>=i){
        Mans+=B[j];
      }
    }
    ans=max(Mans,ans);
  }
  cout<<ans<<endl;
}