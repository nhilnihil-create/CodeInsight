#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,ans=0;
  cin>>N;
  for(int i=105;i<=N;i+=2){
    int cnt=0;
    for(int j=1;j<=i;j++)
      if(i%j==0)cnt++;
    if(cnt==8)ans++;
  }
  cout<<ans<<endl;
}