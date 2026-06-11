#include<iostream>
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
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;


int main(){
  int N; cin >> N; int last[202020]; ll dp[202020] = {};
  rep(i, 202020){
    last[i] = -1;
  }
  dp[0] = 1; 
  for(int i=0; i<=N-1; i++){
    int a; cin >> a; a--;
    if(i==0){
      last[a] = i; continue;
    }
    if(last[a]!=-1 && last[a]!=i-1) dp[i] = dp[i-1] + dp[last[a]];
    else dp[i] = dp[i-1];
    dp[i]%=mod;
    //cout << dp[i] << endl;
    //cout << last[a] << endl;
    last[a] = i;
  }
  cout << dp[N-1] << endl;
}
      