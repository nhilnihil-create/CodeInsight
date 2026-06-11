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
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;


int main(){
  int N; cin >> N;
  int t[N+1]; double v[N]; int sum=0; t[0] = 0;
  rep(i, N){
    cin >> t[i+1]; t[i+1]+=t[i];
  }
  rep(i, N){
    cin >> v[i];
  }
  double K[N+1];
  K[0] = 0; K[N] = 0;
  rep(i, N-1){
    K[i+1] = min(v[i], v[i+1]);
  }
  double tmp[2*sum+1]; double ans = 0;
  rep(i, 2*t[N]+1){
    tmp[i] = inf;
    rep(j, N+1){
      tmp[i] = min(tmp[i], K[j]+abs(t[j]-i*0.5)); 
    }
    rep(j, N){
      if(t[j]<=i*0.5 && i*0.5<=t[j+1]) tmp[i] = min(tmp[i], (double)v[j]);
    }
    if(i>0) ans+=(tmp[i]+tmp[i-1])*0.25;
  }
  printf("%.12lf\n", ans);
 }
