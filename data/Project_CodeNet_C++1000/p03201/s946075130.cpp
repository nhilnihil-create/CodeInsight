#include<iostream>
#include <cstring>
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
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;


int main(){
  int N; cin >> N; ll a[N]; map<ll, int>mp;
  rep(i, N){
    cin >> a[i]; mp[a[i]]++;
  }
  int ans = 0;
  sort(a, a+N, greater<ll>());
  rep(i, N){
    if(mp[a[i]]<=0) continue;
    ll k = 1;
    while((ll)pow(2, k)<=a[i]){
      k++;
    }
    ll P = (ll)pow(2, k) - a[i];
    if(mp[P]>0 && P!=a[i]){
      mp[P]--; mp[a[i]]--; ans++;
    }
    else if(mp[P]>1){
      mp[P]-=2; ans++;
    }
    else continue;
  }
  cout << ans << endl;
}