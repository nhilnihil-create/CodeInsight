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
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=1000010;
const ll mod=1e9+7;

int main(){
  int n;
  cin >> n;
  map<int,int> mp;
  rep(i,n){
    int d; cin >> d;
    mp[d]++;
    if(mp[d]>=3){ cout << 0 << endl; return 0; }
  }

  vector<int> pos;
  pos.push_back(0);
  pos.push_back(24);
  bool f = true;
  for(auto it:mp){
    if(it.S==2){
      pos.emplace_back(it.F);
      pos.emplace_back(24 - it.F);
    } else {
      if(f){
        pos.emplace_back(it.F);
        f = !f;
      } else {
        pos.emplace_back(24 - it.F);
        f = !f;
      }
    }
  }
  sort(pos.begin(),pos.end());
  int ans = inf;
  int m = pos.size();
  rep(i,m-1){
    ans = min(ans, pos[i+1]-pos[i]);
  }
  cout << ans << endl;
  return 0;
}