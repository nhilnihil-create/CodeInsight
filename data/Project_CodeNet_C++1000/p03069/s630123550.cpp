#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  string S;
  cin>>N>>S;
  int n=0;
  for(int i=0;i<N;i++)
    if(S[i]=='.')
      n++;
  int ans=n;
  for(int i=0;i<N;i++){
    if(S[i]=='#')
      n++;
    else
      n--;
    ans=min(ans,n);
  }
  cout<<ans<<endl;
}