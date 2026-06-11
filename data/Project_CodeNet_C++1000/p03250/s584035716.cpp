#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  vector<int> A(3);
  rep(i,3)cin>>A[i];
  sort(rbegin(A),rend(A));
  int ans=A[0]*10+A[1]+A[2];
  cout<<ans<<endl;
  return 0;
}