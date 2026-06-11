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
  int N; cin >> N; int a[N], ans[N];
  rep(i, N){
    cin >> a[i];
  }
  bool check[N] = {};
  rep(i, N){
    int cnt = 0, tmpj = -1;
    rep(j, N){
      if(check[j]) continue;
      cnt++;
      if(a[j]==cnt){
        tmpj = j;
      }
    }
    if(tmpj==-1){
      cout << tmpj << endl; return 0;
    }
    ans[N-1-i] = a[tmpj];
    check[tmpj] = true;
  }
  rep(i, N){
    cout << ans[i] << endl;
  }
}
      