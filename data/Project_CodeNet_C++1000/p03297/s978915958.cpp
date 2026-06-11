#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

ll gcd(ll a,ll b){
  return b==0?a:gcd(b,a%b);
}

void solve(){
  ll A,B,C,D;
  cin>>A>>B>>C>>D;

  if(A<B||D<B||C<A%B){
    cout<<"No"<<endl;
    return;
  }else if(C>=B){
    cout<<"Yes"<<endl;
    return;
  }

  ll g=gcd(B,D);
  ll x=(C-A%B)/g+1;
  ll val=A%B+g*x;

  if(val>=B) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}

int main(){
  int T;
  cin>>T;
  rep(i,T) solve();

  return 0;
}
