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
const int inf=1e9+7;
const ll longinf=(1LL<<63) - 600;
const ll mod=1e9+7 ;


int main(){
  int N, K; cin >> N >> K; ll a[N];
  rep(i, N){
    cin >> a[i];
  }
  ll cum[N+1]; cum[0]=0;
  rep(i, N){
    cum[i+1] = cum[i]+a[i];
  }
  vector<ll> b;
  rep(L, N){
    for(int R=L+1; R<=N; R++){
      b.push_back(cum[R] - cum[L]);
    }
  }
  ll ans = 0;
  for(int i=40; i>=0; i--){
    int cnt = 0;
    rep(j, b.size()){
      if((1LL<<i)&b[j]){cnt++;}
    }
    if(cnt>=K){
      rep(j, b.size()){
        if(!((1LL<<i)&b[j])) b[j]=0;
      }
      ans+=(1LL<<i);
    }
  }
  cout << ans << endl; 
}