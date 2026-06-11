#include <bits/stdc++.h>
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
using namespace std;
const int MOD = 1000000007;
const int INF = 1010000000;
const double EPS = 1e-10;
const array<pair<int,int>,4> fd{make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 
//ll



int main(){
  ll n,p;cin>>n>>p;
  ll ans = 1;
  if(n==1){
    cout << p << endl;
    return 0;
  }
  repd(i,2,sqrt(p)+2){
    ll a = 0;
    while(!(p%i)){
        p /= i;
        a++;
    }
    while(a>=n){
      ans *= i;
      a -= n;
    }
  }
  cout << ans << endl;
}
