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

int main(){
  int K;
  cin>>K;
  vector<ll> A(K);
  rep(i,K) cin>>A[i];

  ll low=2,high=2;
  for(int i=K-1;i>=0;i--){
    ll nexLow=low,nexHigh=high;
    nexLow=low+(A[i]-low%A[i])%A[i];
    nexHigh=high-(high%A[i])+A[i]-1;

    low=nexLow;
    high=nexHigh;
    if(low>high){
      cout<<-1<<endl;
      return 0;
    }
  }

  cout<<low<<" "<<high<<endl;

  return 0;
}
