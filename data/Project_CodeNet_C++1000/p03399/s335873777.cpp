#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int A,B,C,D;
  cin>>A>>B>>C>>D;
  int ans=min(A,B)+min(C,D);
  cout<<ans<<endl;
  return 0;
}