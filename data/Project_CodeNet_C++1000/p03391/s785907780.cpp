#include <bits/stdc++.h>
const int INF=1e9,MOD=1e9+7;
const long long LINF=1e18;
using namespace std;
#define int long long
//template

//main
signed main(){
  int N;cin>>N;
  int ans=0;
  std::vector<int> a(N),b(N);
  for(int i=0;i<N;i++)cin>>a[i]>>b[i];
  bool nn=1;for(int i=0;i<N;i++)if(a[i]!=b[i])nn=0;if(nn){cout<<0<<endl;return 0;}
  for(int i=0;i<N;i++)ans+=b[i];
  int m=LINF;
  for(int i=0;i<N;i++)if(a[i]>b[i])m=min(m,b[i]);
  ans-=m;cout<<ans<<endl;
}
