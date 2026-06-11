#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,ans=0;
  cin>>N;
  for(int i=1;i<=N/i-1;i++)
    if(N%i==0 && N/i-1>i)
      ans+=N/i-1;
  cout<<ans<<endl;
}