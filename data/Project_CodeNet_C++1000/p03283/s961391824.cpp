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
  int N, M, Q; cin >> N >> M >> Q; 
  int cnt[500][500] = {};
  rep(i, M){
    int l, r; cin >> l >> r; l--; r--; cnt[l][r]++; 
  }
  rep(i, 500){
    rep(j, 499){
      cnt[i][j+1]+=cnt[i][j];
    }
  }
  rep(i, Q){
    int p, q; cin >> p >> q; p--; q--;
    int ans = 0;
    for(int j=p; j<500; j++){
      ans+=cnt[j][q];
    }
    cout << ans << endl;
  }
}
    
