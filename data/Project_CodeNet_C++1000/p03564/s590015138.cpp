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
constexpr char ln =  '\n';

const int mx=100010;
const ll mod=1e9+7;

int main(){
  ll n,k;
  cin >> n >> k;
  ll ans = 1;
  while(n--){
    if(ans>k){
      ans += k;
    } else {
      ans *= 2;
    }
  }
  cout << ans << ln;
  return 0;
}