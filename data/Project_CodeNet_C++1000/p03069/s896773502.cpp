#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,k=0,ans=0;
  string S;
  cin>>N>>S;
  for(char c:S)
    if(c=='.')
      k++;
  ans=k;
  for(int i=0;i<N;i++){
    if(S[i]=='.')
      k--;
    else
      k++;
    ans=min(ans,k);
  }
  cout<<ans<<endl;
}