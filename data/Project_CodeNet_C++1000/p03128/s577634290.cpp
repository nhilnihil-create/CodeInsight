#include<iostream>
#include <cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;


int main(){
  int N, M; cin >> N >> M; int a[M];
  rep(i, M){
    cin >> a[i];
  }
  int match[9] = {2, 5, 5, 4, 5, 6, 3, 7, 6};
  int dp[N+1];
  rep(i, N+1){
    dp[i] = -inf;
  }
  dp[0] = 0;
  rep(i, N+1){
    rep(j, M){
      if(i-match[a[j]-1]>=0) dp[i] = max(dp[i-match[a[j]-1]] + 1, dp[i]);
    }
  }
  sort(a, a+M, greater<int>());
  int ma = N;
  while(ma != 0){
    rep(i, M){
      if(ma-match[a[i]-1]<0) continue;
      else if(dp[ma]==dp[ma-match[a[i]-1]]+1){
        cout << a[i]; ma -= match[a[i]-1]; break;
      }
    }
  }
  cout << endl;
}