#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int A,B;
  cin>>A>>B;
  int ans=0;
  if((A+B)%2==0)ans=(A+B)/2;
  else ans=(A+B)/2+1;
  cout<<ans<<endl;
  return 0;
}