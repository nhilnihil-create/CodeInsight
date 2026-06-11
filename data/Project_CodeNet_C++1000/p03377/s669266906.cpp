#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int A,B,X;
  cin>>A>>B>>X;
  string ans="NO";
  for(int i=0;i<=B;i++){
    if(A+i==X)ans="YES";
  }
  cout<<ans<<endl;
  return 0;
}
