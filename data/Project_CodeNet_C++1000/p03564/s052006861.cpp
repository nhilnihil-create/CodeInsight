#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int ans=1,N,K;
  cin>>N>>K;
  rep(i,N){
    if(ans*2<ans+K)ans*=2;
    else ans+=K;
  }
  cout<<ans<<endl;
  return 0;
}