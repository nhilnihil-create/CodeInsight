#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;
const long long INF = 1LL<<60;

int main() {
  int64_t N,M,ans=0; cin>>N>>M;
  vector<int64_t> X(N),Y(N),Z(N);
  rep(i,N) cin>>X[i]>>Y[i]>>Z[i];
  for(int temp=0; temp<(1<<3);temp++){
    bitset<3> s(temp);
    vector<int64_t> A(N,0);
    rep(i,N){
      int64_t t=0;
      if(s.test(0)) t+=X[i];
      else t-=X[i];
      if(s.test(1)) t+=Y[i];
      else t-=Y[i];
      if(s.test(2)) t+=Z[i];
      else t-=Z[i];
      A[i]=t;
    }
    sort(A.begin(),A.end());
    reverse(A.begin(),A.end());
    int64_t k=0;
    rep(i,M) k+=A[i];
    ans=max(ans,k);
  }
  cout<<ans<<endl;
}