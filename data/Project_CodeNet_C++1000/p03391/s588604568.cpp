#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

int N;
vector<ll> A,B;

int main(){
  cin>>N;
  A.resize(N);
  B.resize(N);
  rep(i,N) cin>>A[i]>>B[i];

  bool same=true;
  for(int i=0;i<N;i++){
      if(A[i]!=B[i]) same=false;
  }
  if(same){
      cout<<0<<endl;
      return 0;
  }

  ll ans=0;
  ll mi=MOD;
  ll sumb=0;
  for(int i=0;i<N;i++){
      if(A[i]<=B[i]) ans+=A[i];
      else{
          ans+=(A[i]-B[i]);
          sumb+=B[i];
          mi=min(mi,B[i]);
      }
  }

  if(mi<MOD) sumb-=mi;
  ans+=sumb;
  cout<<ans<<endl;

  return 0;
}
