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
  int N; cin >> N;
  vector<pair<int, int>>ans;
  int tmp;
  if(N%2) tmp = N; else tmp = N+1;
  for(int i=1; i<=N; i++){
    for(int j=i+1; j<=N; j++){
      if(i+j!=tmp) ans.push_back({i, j});
    }
  }
  cout << ans.size() << endl;
  rep(i, ans.size()){
    cout << ans[i].first << " " << ans[i].second << endl;
  }
}