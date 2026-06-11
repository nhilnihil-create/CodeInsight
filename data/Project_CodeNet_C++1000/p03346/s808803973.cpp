
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
#include <random>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define pll pair<ll,ll>
#define pint pll
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
  int n;
  cin >> n;
  int p[n],pos[n];
  rep(i,n){
    cin >> p[i];
    p[i]--;
    pos[p[i]]=i;
  }
  ll ans=0;
  int cnt=p[0];
  rep(i,n){
    ll len=1;
    while(i+1<n && pos[i]<pos[i+1]){
      len++;
      i++;
    }
    ans=max(ans,len);
  }
  cout << n-ans << endl;
return 0;}