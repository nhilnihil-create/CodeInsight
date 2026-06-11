#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
  int N,P;
  cin>>N>>P;
  int ans=1;
  if(N==1){cout<<P<<endl;return 0;}
  for(int i=1;pow(i,N)<=P;i++){
    int j=pow(i,N);
    if(P%j==0)ans=i;
  }
  cout<<ans<<endl;
}
