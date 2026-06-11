#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int N;
  cin>>N;
  string ans="Christmas";
  if(N==24)ans="Christmas Eve";
  if(N==23)ans="Christmas Eve Eve";
  if(N==22)ans="Christmas Eve Eve Eve";
  cout<<ans<<endl;
}