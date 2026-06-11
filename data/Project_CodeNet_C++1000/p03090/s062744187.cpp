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
#define REP(i,m,n) for(ll i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
constexpr char ln = '\n';

const int mx=200010;
const ll mod=1e9+7;


int main(){
  int n;
  cin >> n;
  vector<P> e;
  if(n%2){
    REP(i,1,n){
      e.emplace_back(n,i);
    }    
    n--;
  }
  REP(i,1,n/2+1)REP(j,i+1,n/2+1){
    e.emplace_back(i,j);
    e.emplace_back(i,n-j+1);
    e.emplace_back(n-i+1,j);
    e.emplace_back(n-i+1,n-j+1);
  }

  cout << e.size() << ln;
  for(auto it:e){
    cout << it.F << " " << it.S << ln;
  }
  return 0;
}