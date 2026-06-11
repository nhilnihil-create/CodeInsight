#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<=N;i++)

signed main(){
  int N;
  cin>>N;
  int C=N/4,D=N/7;
  string ans="No";
  rep(i,C){
    rep(j,D){
      if((4*i+7*j)==N)ans="Yes";
    }
  }
  cout<<ans<<endl;
  return 0;
}