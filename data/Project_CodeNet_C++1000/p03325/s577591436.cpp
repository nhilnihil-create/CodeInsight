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
  int ans=0;
  rep(i,N){
    while(A[i]%2==0){
      ans+=1;
      A[i]/=2;
    }
  }
  cout<<ans<<endl;
}