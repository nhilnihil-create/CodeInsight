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

const int P=200020;

int main(){
  int N;
  cin>>N;
  vector<int> C(N);
  rep(i,N) cin>>C[i];

  vector<int> back(P+1,0);
  vector<ll> dp(N+1,0);
  dp[1]=1;
  back[C[0]]=1;
  for(int i=1;i<N;i++){
    if(back[C[i]]==i) dp[i+1]=dp[i];
    else dp[i+1]=(dp[i]+dp[back[C[i]]])%MOD;
    back[C[i]]=i+1;
  }
  cout<<dp[N]<<endl;


  return 0;
}
