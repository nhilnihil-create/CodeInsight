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

const int mx=100010;
const ll mod=1e9+7;


int main(){
  ll n,a,b;
  cin >> n >> a >> b;
  if(a+b-1>n || a*b<n){ cout << -1 << endl; return 0; }

  vector<int> lisdl;
  rep(i,b){
    int d = 1;
    if(a>1){
      if(i<(n-b)/(a-1)) d=a;
      if(i==(n-b)/(a-1)) d=1+(n-b)%(a-1);
    }
    int st = n+1-lisdl.size()-d;
    rep(j,d) lisdl.emplace_back(st+j);
  }

  for(auto ans:lisdl){
    cout << ans << " ";
  }
  cout << endl;

  return 0;
}