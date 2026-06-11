#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  string S;
  cin>>S;
  int ans=0;
  rep(i,4){
    if(S[i]=='+')ans+=1;
    else ans-=1;
  }
  cout<<ans<<endl;
  return 0;
}