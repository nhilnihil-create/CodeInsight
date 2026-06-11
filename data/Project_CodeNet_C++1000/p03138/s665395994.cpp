#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
int64_t MOD=1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int64_t N,K; cin>>N>>K;
  vector<int64_t> S(40,0),T(N);
  rep(i,N){
    int64_t A; cin>>A;
    T.at(i)=A;
    rep(j,40){
      if((A>>j)&1LL) S[j]++;
    }
  }
  int64_t ans=0,x=0;
  for(int i=39;i>=0;i--){
    if(S[i]<=N-S[i] && (x+(1LL<<i)<=K)){
      x+=(1LL<<i);
    }
  }
  rep(i,N) ans+=(x^T.at(i));
  cout<<ans<<endl;
}
