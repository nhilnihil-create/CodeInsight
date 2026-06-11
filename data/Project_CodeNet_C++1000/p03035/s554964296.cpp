#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int N,M;
  cin>>N>>M;
  int ans=M;
  if(N<13)ans/=2;
  if(N<=5)ans=0;
  cout<<ans<<endl;
}