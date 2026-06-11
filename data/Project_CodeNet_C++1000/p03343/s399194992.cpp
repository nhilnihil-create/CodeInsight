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
  int n,k,q;
  cin >> n >> k >> q;
  vector<ll> a(n);
  rep(i,n)cin>>a[i];
  ll ans = longinf;
  rep(i,n){
    vector<vector<ll>> ch;
    ch.push_back({});
    rep(j,n){
      if(a[j]>=a[i]){
        ch.back().emplace_back(a[j]);
      } else {
        ch.push_back({});
      }
    }
    vector<ll> b;
    for(auto& it:ch){
      sort(it.rbegin(),it.rend());
      while(it.size()>=k){
        b.emplace_back(it.back());
        it.pop_back();
      }
    }
    sort(b.begin(),b.end());
    if(b.size()>=q) ans = min(ans, b[q-1]-b[0]);
  }
  cout << ans << endl;
  return 0;
}