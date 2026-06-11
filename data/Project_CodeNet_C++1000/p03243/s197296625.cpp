#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int N,ans=111;
  cin>>N;
  rep(i,10){
    if(ans<N){
      ans+=111;
    }
  }
  cout<<ans<<endl;
  return 0;
}