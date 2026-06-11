#include <bits/stdc++.h>
const int INF=1e9,MOD=1e9+7;
const long long LINF=1e18;
using namespace std;
#define int long long
//template

//main
signed main(){
  int N,X;cin>>N>>X;
  std::vector<int> v(N),w(N+1);
  for(int i=0;i<N;i++)cin>>v[i];
  w[0]=0;for(int i=0;i<N;i++)w[i+1]=w[i]+v[i];
  int fans=LINF;
  for(int i=1;i<=N;i++){
    int ans=X*(N+i);
    ans+=(w[N]-w[N-i])*5;
    for(int j=i;j<N;j+=i){
      ans+=(w[N-j]-w[max(N-j-i,0LL)])*(2*j/i+3);
      if(ans>LINF||ans<0){ans=LINF;break;}
    }
    fans=min(ans,fans);
  }
  cout<<fans<<endl;
}
