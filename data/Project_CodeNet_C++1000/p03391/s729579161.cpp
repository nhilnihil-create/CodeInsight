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
  vector<ll> a(n),b(n);
  ll ans = 0;
  ll bmin = longinf;
  rep(i,n){
    cin >> a[i] >> b[i];
    ans += a[i];
    if(a[i]>b[i]){
      bmin = min(bmin, b[i]);
    }
  }
  if(a==b){cout<<0<<endl; return 0;}
  cout << ans-bmin << endl;
  return 0;
}