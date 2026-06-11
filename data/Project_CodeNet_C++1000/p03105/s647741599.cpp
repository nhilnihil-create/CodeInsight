#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=1;i<N;i++)

signed main(){
  int A,B,C;
  cin>>A>>B>>C;
  int ans=0;
  if(A*C<=B)ans=C;
  else ans=B/A;
  cout<<ans<<endl;
}