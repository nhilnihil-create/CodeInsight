#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=1;i<=N;i++)

signed main(){
  int A,B;
  cin>>A>>B;
  string ans="No";
  rep(i,3){
    if(A*B*i%2==1)ans="Yes";
  }
  cout<<ans<<endl;
}