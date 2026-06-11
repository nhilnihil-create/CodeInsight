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
  int N; ll K; cin >> N >> K; ll a[N];
  rep(i, N){
    cin >> a[i];
  }
  ll X = 0;
  rep(i, 41){
    int cnt=0;
    rep(j, N){
      if((1LL<<(40-i))&a[j]) cnt++;
    }
    if(cnt<(N+1)/2 && X+(1LL<<(40-i))<=K){
      X+=(1LL<<(40-i));
    }
  }
  //cout << X << endl;
  ll ans=0;
  rep(i, N){
    ans+=a[i]^X;
  }
  cout << ans << endl;
}