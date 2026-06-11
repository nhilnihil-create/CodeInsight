#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  string S;
  cin>>S;
  int ans=700;
  rep(i,3)if(S[i]=='o')ans+=100;
  cout<<ans<<endl;
}