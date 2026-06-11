#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  vector<int> vec(3);
  rep(i,3)cin>>vec[i];
  sort(all(vec));
  int ans=vec[2]-vec[1];
  if((vec[1]-vec[0])%2==0)ans+=(vec[1]-vec[0])/2;
  else ans+=(vec[1]-vec[0]+1)/2+1;
  cout<<ans<<endl;
}