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
  vector<int> p(n);
  rep(i,n){
    cin >> p[i];
  }
  map<int,int> mp;
  for(int i=n-1; i>=0; i--){
    if(mp.find(p[i]+1)!=mp.end()){
      mp[p[i]] = mp[p[i]+1]+1;
    } else {
      mp[p[i]] = 1;
    }
  }

  int maxi = 0;
  for(auto it:mp){
    maxi = max(maxi, it.S);
  }
  int ans = n-maxi;
  cout << ans << ln;
  return 0;
}