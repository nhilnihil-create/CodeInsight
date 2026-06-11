#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,n=0,m=0;
  cin>>N;
  int ans=100000000;
  for(int i=0;i<=N;i++){
    int cnt=0;
    for(int j=i;j>0;cnt+=j%9,j/=9);
    for(int j=N-i;j>0;cnt+=j%6,j/=6);
    ans=min(ans,cnt);
  }
  cout<<ans<<endl;
}