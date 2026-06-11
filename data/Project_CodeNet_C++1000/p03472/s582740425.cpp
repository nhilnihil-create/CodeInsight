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
  int n,h;
  cin >> n >> h;
  vector<int> a(n),b(n);
  rep(i,n) cin >> a[i] >> b[i];
  sort(a.rbegin(),a.rend());
  sort(b.begin(),b.end());
  int ans = 0;
  while(b.back()>a[0] && !b.empty() && h>0){
    ans++;
    h -= b.back();
    b.pop_back();
  }
  if(h<=0) { cout << ans << endl; return 0;}
  ans += (h+a[0]-1)/a[0];
  cout << ans << endl;
  return 0;
}