#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=1;i<=N;i++)


signed main(){
  int N,ans;
  cin>>N;
  if(N%2==1)ans=2*N;
  else ans=N;
  cout<<ans<<endl;
  return 0;
}