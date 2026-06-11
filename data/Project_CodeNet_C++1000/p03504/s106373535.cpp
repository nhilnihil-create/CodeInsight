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
  int N, A; cin >> N >> A; int kosu[202020] = {};
  int s[N], t[N], C[N];
  rep(i, N){
    cin >> s[i] >> t[i] >> C[i];
    C[i]--;
  }
  rep(i, 30){
    int shiyo[202020] = {};
    rep(j, N){
      if(C[j]==i){
        shiyo[2*s[j] - 1]++; shiyo[2*t[j]]--;
      }
    }
    rep(j, 202010){
      shiyo[j+1]+=shiyo[j];
    }
    rep(j, 202010){
      if(shiyo[j]>0) kosu[j]++;
    }
  }
  int ans = 0;
  rep(i, 202010){
    ans = max(ans, kosu[i]);
  }
  cout << ans << endl;
}