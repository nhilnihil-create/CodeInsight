#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int A,B,C;
  cin>>A>>B>>C;
  string ans="No";
  if((A+B)>=C)ans="Yes";
  cout<<ans<<endl;
  return 0;
}