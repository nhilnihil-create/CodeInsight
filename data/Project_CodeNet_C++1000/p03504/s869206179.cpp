#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N,C,s,t,c,T=0; cin>>N>>C;
  vector<vector<bool>>Z(31, vector<bool>(100001,false));
  for(int i=0; i<N; i++){
    cin>>s>>t>>c;
    T=max(T,t);
    for(int j=s; j<=t; j++) Z[c][j]=true;
  }
  ll ans=0;
  for(int i=1; i<=T; i++){
    ll temp=0;
    for(int j=1; j<=30; j++){if(Z[j][i])temp++;}
    ans=max(ans,temp);
  }
  cout<<ans<<endl;
}