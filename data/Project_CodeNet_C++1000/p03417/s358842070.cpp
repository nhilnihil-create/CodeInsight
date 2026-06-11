#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int N,M;
  cin>>N>>M;
  int ans=0;
  if(N==1&&M==1){
    ans=1;
    cout<<ans<<endl;
    return 0;
  }
  if(N==1||M==1){
    if(N==1)ans=M-2;
    if(M==1)ans=N-2;
    cout<<ans<<endl;
    return 0;
  }
  ans=(N-2)*(M-2);
  cout<<ans<<endl;
}