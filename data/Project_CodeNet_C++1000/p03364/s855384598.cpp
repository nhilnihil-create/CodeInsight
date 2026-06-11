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
  int N; cin >> N; string S[N];
  rep(i, N){
    cin >> S[i];
  }
  int cnt = 0;
  rep(i, N){
    bool can = true;
    rep(j, N){
      rep(k, N){
        if(S[j][(k+i)%N]!=S[k][(j+i)%N]){
          can = false; 
        }
      }
    }
    if(can) cnt++;
  }
  cnt*=N;
  cout << cnt << endl;
}