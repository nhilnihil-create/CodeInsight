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
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> a(n+1,0);
  rep(i,n){
    a[i+1] = a[i] + (s[i]=='#'?1:0);
  }
  int ans = inf;
  rep(i,n+1){
    ans = min(ans, a[i]+(n-i-(a[n]-a[i])));
  }
  cout << ans << endl;
  return 0;
}