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
  int N; cin >> N; int a[N]; int mi=inf, ma=-inf, mii, mai;
  cout << 2*N- 2 << endl;
  rep(i, N){
    cin >> a[i];
    if(mi>a[i]){
      mi=a[i]; mii=i+1;
    }
    if(ma<a[i]){
      ma=a[i]; mai=i+1;
    }
  }
  bool plus = false;
  if(ma>0 && abs(ma)>abs(mi)) plus = true;
  if(plus){
    rep(i, N){
      if(i+1==mai) continue;
      cout << mai << " " << i+1 << endl;
    }
    rep(i, N-1){
      cout << i+1 << " " << i+2 << endl;
    }
    return 0;
  }
  rep(i, N){
    if(i+1==mii) continue;
    cout << mii << " " << i+1 << endl;
  }  
  for(int i=N; i>=2; i--){
    cout << i << " " << i-1 << endl;
  }
}