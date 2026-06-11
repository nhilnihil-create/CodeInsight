#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
const ll M=1000000007;
//------------------------------------------//

int main(){
  int N,K;cin>>N>>K;
  vector<int> h(N);
  rep(i,N) cin>>h[i];
  sort(h.begin(),h.end());
  
  int ans=M;
  rep(i,N-K+1){
    ans=min(ans,h[i+K-1]-h[i]);
  }
  cout<<ans<<endl;
}