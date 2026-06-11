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

#define bit(n,k) ((n>>k)&1) //*n no k bit me 1 or 0*/

int main(){
  int n;
  string s;
  cin >> n >> s;
  unordered_map<string,ll> mp;
  rep(i,(1<<n)){
    string a="",b="";
    rep(j,n){
      if(bit(i,j)){
        a.push_back(s[j]);
      } else {
        b.push_back(s[j]);
      }
    }
    reverse(b.begin(),b.end());
    string t = a + ":" + b;
    mp[t]++;
  }

  ll ans = 0;

  rep(i,(1<<n)){
    string a="",b="";
    rep(j,n){
      if(bit(i,j)){
        a.push_back(s[j+n]);
      } else {
        b.push_back(s[j+n]);
      }
    }
    reverse(a.begin(),a.end());
    string t = a + ":" + b;
    ans += mp[t];
  }
  cout << ans << ln;
  return 0;
}