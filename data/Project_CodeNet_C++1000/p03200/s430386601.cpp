#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  string S;
  cin>>S;
  int N=S.size(),ans=0,cnt=0;
  for(int i=0;i<N;i++){
    if(S[i]=='B')
      cnt++;
    else
      ans+=cnt;
  }
  cout<<ans<<endl;
}