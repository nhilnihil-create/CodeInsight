#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

ll sum[2][101010];
int dx[3]={0,-1,0},dy[3]={0,0,-1};

int main(){
  int N; cin>>N;
  vector<int> L(N),R(N);
  rep(i,N) cin>>L[i]>>R[i];
  sort(L.rbegin(),L.rend());
  sort(R.begin(),R.end());
  rep(i,N){
    sum[0][i+1]=sum[0][i]+L[i];
    sum[1][i+1]=sum[1][i]+R[i];
  }
  ll ans=0;
  for(int k=1;k<=N;k++){
    rep(i,3) ans=max(ans,2*(sum[0][k+dx[i]]-sum[1][k+dy[i]]));
  }
  cout<<ans<<endl;
  return 0;
}
