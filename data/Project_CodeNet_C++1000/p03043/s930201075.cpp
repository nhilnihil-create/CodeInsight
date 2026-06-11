#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,K;
  cin>>N>>K;
  long double ans=0;
  for(int i=1;i<=N;i++){
    long double a=1;
    for(int j=i;j<K;j*=2)
      a/=2;
    ans+=a;
  }
  cout<<fixed<<setprecision(16)<<ans/N<<endl;
}