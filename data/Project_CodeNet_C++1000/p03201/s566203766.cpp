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

ll powll(ll n,ll k){ ll ret=1; while(k){ if(k&1)ret=ret*n; n=n*n; k>>=1; } return ret; }

int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  map<ll,int> mp;
  rep(i,n){
    cin >> a[i];
    mp[a[i]]++;
  }
  sort(a.rbegin(),a.rend());
  int ans = 0;
  rep(i,n){
    if(mp[a[i]]<=0) continue;
    ll tmp = floorl(log2(a[i]));
    ll nx = powll(2,tmp+1);
    if(mp[nx-a[i]]>0){
      if(nx==2*a[i] && mp[a[i]]==1) continue;
      ans++;
      mp[nx-a[i]]--;
      mp[a[i]]--;
    }
  }
  cout << ans << ln;
  return 0;
}