#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
const ll M=1000000007;
//------------------------------------------//

int main(){
  int N,M,C;cin>>N>>M>>C;
  int B[M];
  int A[N][M];
  rep(i,M) cin>>B[i];
  rep(i,N){
      rep(j,M){
          cin>>A[i][j];
      }
  }
  int ans=0;
  rep(i,N){
      int cnt=C;
      rep(j,M){
          cnt+=A[i][j]*B[j];
      }
      if(cnt>0) ans++;
  }
  cout<<ans<<endl;
}
