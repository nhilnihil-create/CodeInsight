#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N,K,ans=0;
  cin>>N>>K;
  if(K==0){
    cout<<N*N<<endl;
    return 0;
  }
  for(int b=K+1;b<=N;b++)
    ans+=N/b*(b-K)+max(0LL,N%b-K+1);
  cout<<ans<<endl;
}