#include <bits/stdc++.h>
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
constexpr char ln = '\n';

const int mx=100010;
const ll mod=1e9+7;

int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  ll ans = 0;
  rep(i,n){
    cin >> a[i];
  }
  if(a[0]!=0){ cout << -1 << ln; return 0; }
  REP(i,1,n){
    if(a[i]==1+a[i-1]){ ans++; continue; }
    if(a[i]>1+a[i-1]){ cout << -1 << ln; return 0; }
    ans += a[i];
  }
  cout << ans << ln;
  return 0;
}