#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int A,B,C,D;
  cin>>A>>B>>C>>D;
  string ans="No";
  if(abs(A-C)<=D)ans="Yes";
  if(abs(A-B)<=D&&abs(B-C)<=D)ans="Yes";
  cout<<ans<<endl;
}