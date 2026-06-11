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
  int a, b; cin >> a >> b;
  cout << "100 100" << endl;
  char ans[100][100];
  rep(i, 100){
    rep(j, 100){
      if(i<50) ans[i][j]='#';
      else ans[i][j]='.';
    }
  }
  int cnta = a-1;
  rep(i, 50){
    rep(j, 100){
      if(cnta==0) goto NEXTA;
      if(!(i%2) && !(j%2)){
        ans[i][j]='.'; cnta--;
      }
    }
  }
  NEXTA:;
  int cntb = b-1;
  for(int i=50; i<100; i++){
    rep(j, 100){
      if(cntb==0) goto NEXTB;
      if((i%2) && !(j%2)){
        ans[i][j]='#'; cntb--;
      }
    }
  }
  NEXTB:;
  rep(i, 100){
    rep(j, 100){
      cout << ans[i][j];
      if(j==99) cout << endl;
    }
  }
}