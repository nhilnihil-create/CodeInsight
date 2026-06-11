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
  int M; ll K; cin >> M >> K;
  ll ans[1LL<<(M+1)]; ll cnt = 0;
  if(K>=(1LL<<M) || (M==1 && K==1)){
    cout << -1 << endl; return 0;
  }
  if(M==1 && K==0){
    cout << "0 0 1 1" << endl; return 0;
  }
  rep(i, 1LL<<M){
    if(i==K){
      ans[(1LL<<M)-1] = K;
      ans[(1LL<<(M+1))-1] = K;
    }
    else{
      ans[cnt] = i;
      ans[(1LL<<(M+1))-2-cnt] = i;
      cnt++;
    }
  }
  rep(i, 1<<(M+1)){
    if(i!=0) cout << " "; cout << ans[i];
  }
  cout << endl;
}
